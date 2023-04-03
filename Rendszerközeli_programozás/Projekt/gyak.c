#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <signal.h>

#define MAX_BUFFER_SIZE 100

void SendViaFile(int *Values, int NumValues)
{
    chdir(getenv("HOME"));
    FILE *f;
    f = fopen("Measurement.txt", "w");
    for (int i = 0; i < NumValues; i++)
    {
        fprintf(f,"%d\n", Values[i]);
    }
    fclose(f);
    int Search = FindPID();
    if (Search == -1)
    {
        fprintf(stderr, "nem talál fogadó üzemmódban működőfolyamatot");
        exit(10);
    }
    else
    {
        kill(Search,SIGUSR1);
    }
}


void BMPcreator(int *Values, int NumValues)
{
    int fd = open("valami.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    // kiszámítjuk a paddinget(azokat a 0-kat, amik szükségesek ahhoz, hogy osztható legyen maradéknélkül 32-vel)
    // condition ? ifTrue : ifFalse
    int padded_values = NumValues % 32 == 0 ? 0 : NumValues + (32 - (NumValues % 32));
    printf("values: %d\n", NumValues);
    printf("padded values: %d\n", padded_values);

    // File Mérete 62=dib+header+rgb
    int file_size = 62 + ((NumValues * padded_values) / 8); // soroknak
    printf("The size of the file will be: %d B", file_size);

    // A tömbünk
    unsigned char *header = calloc(file_size, sizeof(char));
    puts("");

    // Signature ("BM") 2 bytes big endian header[0-1]
    header[0] = 66;
    header[1] = 77;

    // File size in bytes 4 bytes little endian header[2-5]
    for (int i = 0; i < 4; i++)
    {
        unsigned int tmp = file_size;
        header[i + 2] = (tmp >> i * 8) & 0b11111111;
    }

    // Unused (0) 4 bytes little endian header[6-9]
    for (int i = 6; i < 10; i++)
    {
        header[i] = 0;
    }

    // Pixel Array offset (62) 4 bytes little endian header[10-13]
    for (int i = 0; i < 4; i++)
    {
        unsigned int tmp = 62;
        header[i + 10] = (tmp >> i * 8) & 0b11111111;
    }

    //////////////////////////////////////////////////////////////////////////////

    // DIB header making//

    // DIB header size (40) 4 bytes little endian [14-17]
    for (int i = 0; i < 4; i++)
    {
        unsigned int tmp = 40;
        header[i + 14] = (tmp >> i * 8) & 0b11111111;
    }

    // Image width in pixel 4 bytes little endian [18-21]
    for (int i = 0; i < 4; i++)
    {
        unsigned int tmp = NumValues;
        // unsigned int tmp=5000;
        header[i + 18] = (tmp >> i * 8) & 0b11111111;
    }

    // Image height in pixel 4 bytes little endian [22-25]
    for (int i = 0; i < 4; i++)
    {
        // unsigned int tmp=5000;
        unsigned int tmp = NumValues;
        header[i + 22] = (tmp >> i * 8) & 0b11111111;
    }

    // Planes (1) 2 bytes little endian [26-27]
    for (int i = 0; i < 2; i++)
    {
        unsigned short tmp = 1;
        header[i + 26] = (tmp >> i * 8) & 0b11111111;
    }

    // Bits/pixel (1) 2 bytes little endian header[28-29]
    for (int i = 0; i < 2; i++)
    {
        unsigned short tmp = 1;
        header[i + 28] = (tmp >> i * 8) & 0b11111111;
    }

    // Compression (0) 4 bytes little endian [30-33]
    for (int i = 0; i < 4; i++)
    {
        header[i + 30] = 0;
    }

    // Image size (0) 4 bytes little endian [34-37]
    for (int i = 0; i < 4; i++)
    {
        header[i + 34] = 0;
    }

    // Horizontal pixel/meter (3937) 4 bytes little endian [38-41]
    for (int i = 0; i < 4; i++)
    {
        unsigned int tmp = 3937;
        header[i + 38] = (tmp >> i * 8) & 0b11111111;
    }

    // Vertical pixel/meter (3937) 4 bytes little endian [42-45]
    for (int i = 0; i < 4; i++)
    {
        unsigned int tmp = 3937;
        header[i + 42] = (tmp >> i * 8) & 0b11111111;
    }

    // Colors in palette (0) 4 bytes little endian [46-49]
    for (int i = 0; i < 4; i++)
    {
        header[i + 46] = 0;
    }

    // Used palette colors (0) 4 bytes little endian [50-53]
    for (int i = 0; i < 4; i++)
    {
        header[i + 50] = 0;
    }

    // 0,102,204 r,g,b
    header[54] = 204; // color 0:blue
    header[55] = 102; // color 0: green
    header[56] = 0;   // color 0:red
    header[57] = 127; // color 0: alpha

    header[58] = 0; // color 1:blue
    header[59] = 0; // color 1:green
    header[60] = 0; // color 1:red
    header[61] = 0; // color 1:alpha
    for (int i = 62; i < file_size; i++)
    {
        header[i] = 0;
    }

    write(fd, header, file_size);
}

void ReceiveViaFile(int sig)
{
    FILE *f; // fájlkezelő
    chdir(getenv("HOME")); // home könyvtárba lépés
    f = fopen("Measurement.txt", "r"); // fájl megnyitása olvasásra
    char *buffer=malloc(MAX_BUFFER_SIZE*sizeof(char)); // buffer létrehozása
    int *Values=malloc(1*sizeof(int)); // tömb létrehozása
    int index=0; // index létrehozása

    while (fgets(buffer,MAX_BUFFER_SIZE,f)!=NULL) // fájl beolvasása soronként és a bufferbe mentése
    {
        // printf("%s",buffer);
        Values[index]=atoi(buffer); // bufferből számot készítés
        index++; // index növelése
        Values=realloc(Values,(index+1)*sizeof(int)); // tömb átméretezése
        printf("%d\n",Values[index-1]); // kiíratás
    }
    BMPcreator(Values,index); // BMP létrehozása
    fclose(f); // fájl bezárása
    free(buffer); // buffer felszabadítása
}
int main()
{
    ReceiveViaFile(1);
}

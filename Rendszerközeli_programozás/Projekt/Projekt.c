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

struct tm *T;
int MERT_DARAB = 0;

void BMPcreator(int *Values, int NumValues);

int Measurement(int **Values);

void idokezeles(struct tm **T);

int main(int argc, char *argv[])
{
    bool version = false, help = false, send = true, receive = false, file = true, socket = false;

    if (strcmp(argv[0], "./chart") != 0)
    {
        printf("A program futtathato allomanyanak neve nem chart!\n");
        return EXIT_FAILURE;
    }

    // a program módjainak elszottására szolgáló ciklus
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--version") == 0)
        {
            version = true;
        }
        else if (strcmp(argv[i], "--help") == 0)
        {
            help = true;
        }
        else if (strcmp(argv[i], "-send") == 0)
        {
            send = true;
            receive = false;
        }
        else if (strcmp(argv[i], "-receive") == 0)
        {
            send = false;
            receive = true;
        }
        else if (strcmp(argv[i], "-file") == 0)
        {
            file = true;
            socket = false;
        }
        else if (strcmp(argv[i], "-socket") == 0)
        {
            file = false;
            socket = true;
        }
        else
        {
            help = true;
        }
    }
    //----------------------------------------------

    // a program módjainak kiírására szolgáló ciklus
    if (version)
    {
        pr
        printf("Verzio szam: 1.0\nElkeszitesi datum: 2023.02.14\nSzerzo: Lengyel Szilard Ferenc\n");
        return EXIT_SUCCESS;
    }
    else if (help)
    {
        printf("A program hasznalata:\n --version: paranccsal, lekerdezheto a program verzioszama, az elkeszitesi datum es a szerzo neve.\n --help: paranccsal, lekerdezheto a program hasznalata.\n-send vagy -receive paranccsal, valasztani lehet a program uzemmodjai kozott(def.: send).\n-file' vagy -socket paranccsal, valasztani lehet a program kommunikacios modjai kozott.(def.: file)\n");
        return EXIT_SUCCESS;
    }

    //----------------------------------------------

    if (send)
    {
        printf("Send modban fut a program.\n");
    }
    else if (receive)
    {
        printf("Receive modban fut a program.\n");
    }

    //----------------------------------------------

    if (file)
    {
        printf("File a kommunikacios modban fut a program\n");
    }
    else if (socket)
    {
        printf("Socket a kommunkacios modban fut a program\n");
    }
    //----------------------------------------------
    printf("Szuper, lefutott a program!\n");

    // véletlen szám generálással, 0 val kezdodik, fel 1, le -1 vagy 0, egy tömbbe
    // malloccal foglaljuk

    idokezeles(&T);
    int *Mert_ertekek;
    int Eloallitott_ertekek = Measurement(&Mert_ertekek);
    printf("Az eloallitott darabszam: %d\n", Eloallitott_ertekek);

    // Testing only BMP creatinon!
    BMPcreator(Mert_ertekek, Eloallitott_ertekek);
    // End of testing

    return EXIT_SUCCESS;
}

void BMPcreator(int *Values, int NumValues)
{
    int fd = open("valami.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    // kiszámítjuk a paddinget(azokat a 0-kat, amik szükségesek ahhoz, hogy osztható legyen maradéknélkül 32-vel)
    // condition ? ifTrue : ifFalse
    int padded_values = NumValues % 32 == 0 ? 0 : NumValues+(32 - (NumValues % 32));
    printf("values: %d\n", NumValues);
    printf("padded values: %d\n", padded_values);

    // File Mérete 62=dib+header+rgb
    int file_size = 62 + ((NumValues*padded_values) / 8); //soroknak
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
        unsigned int tmp=NumValues;
        // unsigned int tmp=5000;
        header[i + 18] = (tmp >> i * 8) & 0b11111111;
    }

    // Image height in pixel 4 bytes little endian [22-25]
    for (int i = 0; i < 4; i++)
    {
        // unsigned int tmp=5000;
        unsigned int tmp=NumValues;
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
    header[54]=204; //color 0:blue
    header[55]=102;//color 0: green
    header[56]=0; //color 0:red
    header[57]=127; //color 0: alpha

    header[58]=0; //color 1:blue
    header[59]=0; //color 1:green
    header[60]=0; //color 1:red
    header[61]=0; //color 1:alpha
    for (int i = 62; i < file_size; i++)
    {
        header[i]=0;
    }
    
    write(fd, header, file_size);
}

void idokezeles(struct tm **T)
{
    time_t T1;
    int T2;
    T2 = time(&T1);
    *T = localtime(&T1);

    if ((*T)->tm_min > 0 && (*T)->tm_min < 15)
    {
        MERT_DARAB = ((*T)->tm_min * 60) + (*T)->tm_sec;
    }
    else if ((*T)->tm_min > 15 && (*T)->tm_min < 30)
    {
        MERT_DARAB = (((*T)->tm_min - 15) * 60) + (*T)->tm_sec;
    }
    else if ((*T)->tm_min > 30 && (*T)->tm_min < 45)
    {
        MERT_DARAB = (((*T)->tm_min - 30) * 60) + (*T)->tm_sec;
    }
    else if ((*T)->tm_min > 45)
    {
        MERT_DARAB = (((*T)->tm_min - 45) * 60) + (*T)->tm_sec;
    }

    if (MERT_DARAB < 100)
    {
        MERT_DARAB = 100;
    }
}

int Measurement(int **Values)
{
    srand(time(NULL));
    double rf = 0;
    int tmp = 0;
    *Values = malloc(MERT_DARAB * sizeof(int));

    for (int i = 0; i < MERT_DARAB; i++)
    {
        if (i == 0)
        {
            (*Values)[i] = 0;
            printf("%d ", (*Values)[i]);
        }
        else
        {
            rf = (double)rand() / ((unsigned)RAND_MAX + 1); // 0.0 <= y < 1.0
            if (rf <= 0.428571)
            {
                tmp = tmp + 1;
                (*Values)[i] = tmp;
            }
            else if (rf > 0.428571 && rf <= 0.783409)
            {
                tmp = tmp - 1;
                (*Values)[i] = tmp;
            }
            else
            {
                (*Values)[i] = tmp;
            }
            printf("%d ", (*Values)[i]);
        }
    }
    return MERT_DARAB;
}

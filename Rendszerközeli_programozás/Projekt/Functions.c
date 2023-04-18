#include "Functions.h"
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
#include <math.h>

int Measurement(int **Values)
{
    int MERT_DARAB = idokezeles();
    srand(time(NULL));
    double rf = 0;
    int tmp = 0;
    *Values = malloc(MERT_DARAB * sizeof(int));

    for (int i = 0; i < MERT_DARAB; i++)
    {
        if (i == 0)
        {
            (*Values)[i] = 0;
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
        }
    }
    return MERT_DARAB;
}

int FindPID()
{
    FILE *fp;               // fájl
    DIR *d;                 // mappa
    struct dirent *entry;   // mappa
    int pid = 0;            // pid
    char buff[1000];        // buffer
    int own_pid = getpid(); // saját pid
    d = opendir("/proc/");  // mappa megnyitása

    while ((entry = readdir(d)) != NULL) // mappa bejárása
    {
        if (isdigit(*(entry)->d_name)) // ha szám a fájl neve
        {
            sprintf(buff, "/proc/%s/status", entry->d_name); // fájl elérési útja
            fp = fopen(buff, "r");                           // fájl megnyitása
            fscanf(fp, "Name:\t%s\n", buff);                 // fájl beolvasása
            if (strcmp(buff, "chart") == 0)                  // ha a fájl neve chart
            {
                for (int i = 0; i < 4; i++) // 4 sor útugrása
                {
                    fscanf(fp, "%[^\n]\n", buff); // üres sor beolvasása
                }
                fscanf(fp, "Pid:\t%d\n", &pid); // pid beolvasása
                if (pid != own_pid)             // ha nem saját pid
                {
                    closedir(d); // mappa bezárása
                    fclose(fp);  // fájl bezárása
                    return pid;  // pid visszaadása
                }
            }
        }
    }
    closedir(d);
    return 1;
}

int idokezeles()
{
    int result = 0;
    struct tm *T;
    time_t T1;
    int T2;
    T2 = time(&T1);
    T = localtime(&T1);

    if (T->tm_min > 0 && T->tm_min < 15)
    {
        result = (T->tm_min * 60) + T->tm_sec;
    }
    else if (T->tm_min > 15 && T->tm_min < 30)
    {
        result = ((T->tm_min - 15) * 60) + T->tm_sec;
    }
    else if (T->tm_min > 30 && T->tm_min < 45)
    {
        result = ((T->tm_min - 30) * 60) + T->tm_sec;
    }
    else if (T->tm_min > 45)
    {
        result = ((T->tm_min - 45) * 60) + T->tm_sec;
    }

    if (result < 100)
    {
        result = 100;
    }
    return result;
}

void BMPcreator(int *Values, int NumValues)
{
    int fd = open("Measurements.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    // kiszámítjuk a paddinget(azokat a 0-kat, amik szükségesek ahhoz, hogy osztható legyen maradéknélkül 32-vel)
    // condition ? ifTrue : ifFalse
    int padded_values = NumValues % 32 == 0 ? NumValues : NumValues + (32 - (NumValues % 32));
    printf("values: %d\n", NumValues);
    printf("padded values: %d\n", padded_values);

    // File Mérete 62=dib+header+rgb
    int file_size = 62 + ((NumValues * padded_values) / 8); // soroknak 8-al osztunk, mivel ezek bitek
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
        header[i + 18] = (tmp >> i * 8) & 0b11111111;
    }

    // Image height in pixel 4 bytes little endian [22-25]
    for (int i = 0; i < 4; i++)
    {
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
    header[54] = 40; // color 0:blue
    header[55] = 40; // color 0: green
    header[56] = 40; // color 0:red
    header[57] = 0;   // color 0: alpha

    header[58] = 0; // color 1:blue
    header[59] = 165; // color 1:green
    header[60] = 255; // color 1:red
    header[61] = 0; // color 1:alpha

    // header[62+((NumValues/2+SOR)*(padded_values/8)+OSZLOP)]=0b11111111;

    // header[62 + ((NumValues / 2) * (padded_values / 8))] = 0b10000000;
    // header[62 + ((NumValues / 2 + 1) * (padded_values / 8))] = 0b01000000;
    // header[62 + ((NumValues / 2 + 2) * (padded_values / 8))] = 0b00100000;
    // header[62 + ((NumValues / 2 + 3) * (padded_values / 8))] = 0b00010000;
    // header[62 + ((NumValues / 2 + 4) * (padded_values / 8))] = 0b00001000;
    // header[62 + ((NumValues / 2 + 5) * (padded_values / 8))] = 0b00000100;
    // header[62 + ((NumValues / 2 + 6) * (padded_values / 8))] = 0b00000010;
    // header[62 + ((NumValues / 2 + 7) * (padded_values / 8))] = 0b00000001;

    // header[62 + ((NumValues / 2 + 8) * (padded_values / 8) + 1)] = 0b10000000;
    // header[62 + ((NumValues / 2 + 9) * (padded_values / 8) + 1)] = 0b01000000;
    // header[62+((NumValues/2)*(padded_values/8))]=

    int Buffer_index[8];
    int sum = 0;
    int kulso_index = 0;

    for (int i = 0; i < NumValues; i++)
    {
        Buffer_index[i % 8] = Values[i]; // Azért modulo 8 mivel, csak az első 8 elemre van szükségunk [0-7]

        if (i % 8 == 7 || i == NumValues - 1) // Ellenőrzi, hogy 8 elemnél tartunk-e
        {
            for (int j = 0; j < 8; j++) // Az első ciklus, az elemenkénti ellenőrzéshez
            {
                sum = 0;                    // ebbe mentem el, hogy mennyit kellesz beiratni
                for (int k = 0; k < 8; k++) // második ciklus, ez 8x8-szor fog lefutni
                {
                    if (Buffer_index[j] == Buffer_index[k]) // keresett elem megegyezik-e a aktuálisan nézett elemmel
                    {
                        sum += pow(2, 7 - k); // ha igen, akkor ellentétesen emelem hatványra a 2-őt
                    }
                }
                header[62 + ((NumValues / 2 + Buffer_index[j]) * (padded_values / 8) + kulso_index)] = sum;
                // beiratás, buffer_index[j]=Aktuális elem, a közepéhez képest mennyivel tér el.
                // kulso_index=a bytokat adogatja hozzá sorban
                // ezt egyenlővé tesszük az össze summázott értékkel
            }
            kulso_index++; // következő byte
        }
    }

    write(fd, header, file_size);
    free(header);
    close(fd);
}

void SendViaFile(int *Values, int NumValues)
{
    chdir(getenv("HOME"));
    FILE *f;
    f = fopen("Measurement.txt", "w");
    for (int i = 0; i < NumValues; i++)
    {
        fprintf(f, "%d\n", Values[i]);
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
        kill(Search, SIGUSR1);
    }
}

void ReceiveViaFile(int sig)
{
    const int MAX_BUFFER_SIZE = 100;                       // buffer mérete
    FILE *fda;                                             // fájlkezelő
    chdir(getenv("HOME"));                                 // home könyvtárba lépés
    fda = fopen("Measurement.txt", "r");                   // fájl megnyitása olvasásra
    char *buffer = malloc(MAX_BUFFER_SIZE * sizeof(char)); // buffer létrehozása
    int *Values = malloc(1 * sizeof(int));                 // tömb létrehozása
    int index = 0;                                         // index létrehozása

    while (fgets(buffer, MAX_BUFFER_SIZE, fda) != NULL) // fájl beolvasása soronként és a bufferbe mentése
    {
        Values[index] = atoi(buffer);                        // bufferből számot készítés
        index++;                                             // index növelése
        Values = realloc(Values, (index + 1) * sizeof(int)); // tömb átméretezése
    }
    BMPcreator(Values, index); // BMP létrehozása
    free(buffer);              // buffer felszabadítása
    free(Values);
    fclose(fda);
}

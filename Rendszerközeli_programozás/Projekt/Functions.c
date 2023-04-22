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
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <omp.h>

void Mod_handling(int argc, char **argv, int **modes)
{
    *modes = calloc(4, sizeof(int));
    // modes: 0 - is_send_mode, 1 - is_file_mode,
    (*modes)[0] = 1; // def send mode
    (*modes)[1] = 0; // receive mode
    (*modes)[2] = 1; // def file mode
    (*modes)[3] = 0; // socket mode

    // validate program name
    if (strcmp(argv[0], "./chart") != 0)
    {
        printf("HIBA! Rossz néven probalta futtatni a programot!.\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--version") == 0)
        {
#pragma omp parallel sections
            {
#pragma omp section
                {
                    printf("Verzio: Sokadik ^^\n");
                }
#pragma omp section
                {
                    printf("Utolso simitas: 2023.04.20\n");
                }
#pragma omp section
                {
                    printf("Keszitette: Lengyel Szilard\n");
                }
            }
            exit(1);
        }
        else if (strcmp(argv[i], "--help") == 0)
        {
            printf("Hasznalata: chart [OPTIONS]\n\n"
                   "Options:\n"
                   "  --version      A program verziószámáról ad részletesebb információt\n"
                   "  --help         Elohivja ezt a segito uzenetet\n"
                   "  -send          Kuldo uzemmodba valt (alapertelmezett)\n"
                   "  -receive       Fogado uzemmodva valt\n"
                   "  -file          Fileon keresztuli kommunikaciora valt (alapertelmezett)\n"
                   "  -socket        Socketen keresztuli kommunikaciora valt (alapertelmezett)\n");
            exit(2);
        }
        else if (strcmp(argv[i], "-send") == 0)
        {
            if ((*modes)[0] > 1)
            {
                printf("HIBA! Nem lehet egyszerre ketszer hasznlani a SEND modot!\n");
                exit(1);
            }
            (*modes)[0] += 1;
        }
        else if (strcmp(argv[i], "-receive") == 0)
        {
            if (!(*modes)[1] > 1)
            {
                printf("HIBA! Nem lehet egyszerre ketszer hasznlani a RECEIVE modot!\n");
                exit(1);
            }
            (*modes)[1] += 1;
        }
        else if (strcmp(argv[i], "-file") == 0)
        {
            if (!(*modes)[2] > 1)
            {
                printf("HIBA! Nem lehet egyszerre ketszer hasznlani a FILE modot!\n");
                exit(1);
            }
            (*modes)[2] += 1;
        }
        else if (strcmp(argv[i], "-socket") == 0)
        {
            if ((*modes)[3] > 1)
            {
                printf("HIBA! Nem lehet egyszerre ketszer hasznlani a SOCKET modot!\n");
                exit(1);
            }
            (*modes)[3] += 1;
        }
        else
        {
            printf("Hasznalata: chart [OPTIONS]\n\n"
                   "Options:\n"
                   "  --version      A program verziószámáról ad részletesebb információt\n"
                   "  --help         Elohivja ezt a segito uzenetet\n"
                   "  -send          Kuldo uzemmodba valt (alapertelmezett)\n"
                   "  -receive       Fogado uzemmodva valt\n"
                   "  -file          Fileon keresztuli kommunikaciora valt (alapertelmezett)\n"
                   "  -socket        Socketen keresztuli kommunikaciora valt (alapertelmezett)\n");
            exit(2);
        }
    }
    if ((*modes)[0] > 1 && (*modes)[1] > 0)
    {
        printf("HIBA! Nem lehet egyszerre SEND es RECEIVE modban futtatni a programot!!\n");
        exit(1);
    }
    if ((*modes)[2] > 1 && (*modes)[3] > 0)
    {
        printf("HIBA! Nem lehet egyszerre FILE es SOCKET modban futtatni a programot!!\n");
        exit(1);
    }
}

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
    int pid = -1;           // pid
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
    fclose(fp);
    return pid;
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
    int fd = open("chart.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

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
    header[57] = 0;  // color 0: alpha

    header[58] = 0;   // color 1:blue
    header[59] = 165; // color 1:green
    header[60] = 255; // color 1:red
    header[61] = 0;   // color 1:alpha

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

    // header[62 + ((NumValues - 1) * (padded_values / 8)+)] = 0b11111111;                  // legfelso sor
    // header[62 + ((NumValues - 1) * (padded_values / 8) + NumValues / 16)] = 0b11111111; // legfelso sor
    // header[62 + ((NumValues - 1) * (padded_values / 8) + NumValues / 8)] = 0b11111111;
    // header[62 + ((NumValues / 2) * (padded_values / 8))] = 0b11111111;
    header[62 + NumValues / 16] = 0b11111111; // legalso
    header[62] = 0b11111111;                  // legalso
    header[62+NumValues/8];

    int Buffer_index[8];
    int sum = 0;
    int kulso_index = 0;
    int tmp = 0;
    // for (int i = 0; i < NumValues; i++)
    // {
    //     Buffer_index[i % 8] = Values[i]; // Azért modulo 8 mivel, csak az első 8 elemre van szükségunk [0-7]

    //     if (i % 8 == 7 || i == NumValues - 1) // Ellenőrzi, hogy 8 elemnél tartunk-e
    //     {
    //         for (int j = 0; j < (i % 8) + 1; j++) // Az első ciklus, az elemenkénti ellenőrzéshez
    //         {
    //             sum = 0;                              // ebbe mentem el, hogy mennyit kellesz beiratni
    //             for (int k = 0; k < (i % 8) + 1; k++) // második ciklus, ez 8x8-szor fog lefutni
    //             {
    //                 if (Buffer_index[j] == Buffer_index[k]) // keresett elem megegyezik-e a aktuálisan nézett elemmel
    //                 {
    //                     sum += pow(2, 7 - k); // ha igen, akkor ellentétesen emelem hatványra a 2-őt
    //                 }
    //             }

    //             ///////////////////////////////////////////////////////////////////////////////////////////////
    //             if ((62 + ((NumValues - 1) * (padded_values / 8)) < 62 + ((NumValues / 2 + Buffer_index[j]) * (padded_values / 8) + kulso_index)) && (62 + ((NumValues - 1) * (padded_values / 8) + NumValues / 8) < 62 + ((NumValues / 2 + Buffer_index[j]) * (padded_values / 8) + kulso_index)))
    //             {
    //                 printf("Magas\n");
    //                 header[62 + ((NumValues - 1) * (padded_values / 8) + kulso_index)] = sum; // teteje
    //             }
    //             else if ((62 + ((padded_values / 8)) < 62 + ((NumValues / 2 + Buffer_index[j]) * (padded_values / 8) + kulso_index)) && (62 +((padded_values / 8)+NumValues/8) < 62 + ((NumValues / 2 + Buffer_index[j]) * (padded_values / 8) + kulso_index)))
    //             {
    //                 printf("alacsony");
    //                 header[62 + ((padded_values / 8)) + kulso_index] = sum; // alja
    //             }
    //             else
    //             {
    //                 tmp++;
    //                 printf("%d\n", tmp);
    //                 header[62 + ((NumValues / 2 + Buffer_index[j]) * (padded_values / 8) + kulso_index)] = sum;
    //             }

    //             // beiratás, buffer_index[j]=Aktuális elem, a közepéhez képest mennyivel tér el.
    //             // kulso_index=a bytokat adogatja hozzá sorban
    //             // ezt egyenlővé tesszük az össze summázott értékkel
    //         }
    //         kulso_index++; // következő byte
    //     }
    // }

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
    char *pwd = getenv("PWD");                             // aktuális könyvtár
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
    chdir(pwd);                // vissza az eredeti könyvtárba
    BMPcreator(Values, index); // BMP létrehozása
    free(buffer);              // buffer felszabadítása
    free(Values);
    fclose(fda);
}

void SendViaSocket(int *Values, int NumValues)
{
    /************************ Declarations **********************/
    int PORT_NO = 3333;        // Port Number
    int s;                     // socket ID
    int bytes;                 // received/sent bytes
    int flag;                  // transmission flag
    int receive_bytes;         // receive byte for talking
    char on;                   // sockopt option
    int buffer_received;       // received_int
    unsigned int server_size;  // length of the sockaddr_in server
    struct sockaddr_in server; // address of server

    /************************ Initialization ********************/
    on = 1;
    flag = 0;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(PORT_NO);
    server_size = sizeof server;

    /************************ Creating socket *******************/
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0)
    {
        fprintf(stderr, "Nem sikerult letrehozni a socketet.\n");
        exit(2);
    }
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on);
    setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof on);

    /************************ Sending data **********************/

    bytes = sendto(s, &NumValues, sizeof(int), flag, (struct sockaddr *)&server, server_size);
    if (bytes <= 0)
    {
        fprintf(stderr, "Az [1] kuldes nem sikerult.\n");
        exit(3);
    }
    /************************ Receive data **********************/
    alarm(1);
    receive_bytes = recvfrom(s, &buffer_received, sizeof(int), flag, (struct sockaddr *)&server, &server_size);
    if (receive_bytes < 0)
    {
        fprintf(stderr, "Az [1] fogadas nem sikerult.\n");
        exit(4);
    }
    alarm(0);
    if (bytes == receive_bytes)
    {
        /************************ Sending data **********************/

        bytes = sendto(s, &Values[0], NumValues * sizeof(int), flag, (struct sockaddr *)&server, server_size);
        if (bytes <= 0)
        {
            fprintf(stderr, "A [2] kuldes nem sikerult.\n");
            exit(3);
        }
        /************************ Receive data **********************/

        receive_bytes = recvfrom(s, &Values[0], sizeof(int) * NumValues, flag, (struct sockaddr *)&server, &server_size);
        if (receive_bytes < 0)
        {
            fprintf(stderr, "A [2] fogadas nem sikerult.\n");
            exit(4);
        }

        /// ha a [2] fogadott és küldött nem egyezik akkor itt majd le kellesz állnia úgyszint

        if (bytes != receive_bytes)
        {
            fprintf(stderr, "HIBA! A [2] fogadas es kuldes merete nem egyezik meg!");
            exit(419);
        }
    }
    else
    {
        fprintf(stderr, "HIBA! Az elkuldott, valamint a fogadott bajtok, nem egyeznek!");
        exit(420);
    }

    /************************ Closing ***************************/
    close(s);
}

void ReceiveViaSocket()
{
    /************************ Declarations **********************/
    int s;
    int bytes; // received/sent bytes
    int err;   // error code
    int flag;
    int PORT_NO = 3333;        // transmission flag
    char on;                   // sockopt option
    int buffer;                // datagram buffer area
    unsigned int server_size;  // length of the sockaddr_in server
    unsigned int client_size;  // length of the sockaddr_in client
    struct sockaddr_in server; // address of server
    struct sockaddr_in client; // address of client

    /************************ Initialization ********************/
    on = 1;
    flag = 0;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT_NO);
    server_size = sizeof server;
    client_size = sizeof client;

    /************************ Creating socket *******************/
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0)
    {
        fprintf(stderr, "Nem sikerult letrehozni a socketet.\n");
        exit(2);
    }
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on);
    setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof on);

    /************************ Binding socket ********************/
    err = bind(s, (struct sockaddr *)&server, server_size);
    if (err < 0)
    {
        fprintf(stderr, "Kapcsolodasi hiba\n");
        exit(3);
    }

    while (1)
    { // Continuous server operation
        /************************ Receive data[1] **********************/
        printf("\nVarom az uzenetet...\n");
        // ITT ÉRKEZIK MEG A NUMVALUES
        bytes = recvfrom(s, &buffer, sizeof(int), flag, (struct sockaddr *)&client, &client_size);
        if (bytes < 0)
        {
            fprintf(stderr, "Az [1] fogadas nem sikerult.\n");
            exit(4);
        }

        int *Values = malloc(sizeof(int) * buffer); // itt fogom tárolni a fogadott értékeket
        int NumValues = buffer;                     // itt tárolom a fogadott értékeket
        /************************ Sending data[1] **********************/
        // visszaküldöm a fogadott adatokat
        bytes = sendto(s, &NumValues, sizeof(int), flag, (struct sockaddr *)&client, client_size);
        if (bytes <= 0)
        {
            fprintf(stderr, "Az [1] kuldes nem sikerult.\n");
            exit(5);
        }

        /************************ Receive data[2] **********************/
        // ITT ÉRKEZIK MEG A VALUES
        bytes = recvfrom(s, &Values[0], NumValues * sizeof(int), flag, (struct sockaddr *)&client, &client_size);
        if (bytes < 0)
        {
            fprintf(stderr, "Az [2] fogadas nem sikerult.\n");
            exit(4);
        }

        /************************ Sending data[2] **********************/
        // visszaküldöm a fogadott adatokat
        bytes = sendto(s, &Values[0], sizeof(int) * NumValues, flag, (struct sockaddr *)&client, client_size);
        if (bytes <= 0)
        {
            fprintf(stderr, "Az [2] kuldes nem sikerult.\n");
            exit(5);
        }
        BMPcreator(&Values[0], NumValues);
        free(Values);
    }
}

void SignalHandler(int sig)
{
    if (sig == SIGINT)
    {
        printf("\nA program leall. \nViszlat!\n");
        exit(0);
    }
    else if (sig == SIGUSR1)
    {
        fprintf(stderr, "HIBA! A fajlon keresztuli kuldes szolgaltatas nem elerheto!");
    }
    else if (sig == SIGALRM)
    {
        fprintf(stderr, "A szerver nem valaszol!");
        exit(-1);
    }
}

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

#define MAX_BUFFER_SIZE 100

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
    // // 10 elemü tömb létrehozása
    // int *tomb = malloc(10 * sizeof(int));
    // // tömb feltöltése
    // for (int i = 0; i < 10; i++)
    // {
    //     tomb[i] = i;
    // }
    // // tömb mérete
    // int hossz = 10;

    // SendViaFile(&tomb[0], hossz);
    ReceiveViaFile(1);

}

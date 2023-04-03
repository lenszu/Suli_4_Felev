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

int main(int argc, char *argv[])
{
    bool version = false, help = false, send = true, receive = false, file = true, socket = false;

    if (strcmp(argv[0], "./chart") != 0)
    {
        printf("A program futtathato allomanyanak neve nem chart!\n");
        return EXIT_FAILURE;
    }

    // a program módjainak elosztására szolgáló ciklus
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

    int *Mert_ertekek_TOMB;
    int Eloallitott_ertekek_DARAB = Measurement(&Mert_ertekek_TOMB);
    puts("");
    printf("Az eloallitott darabszam: %d\n", Eloallitott_ertekek_DARAB);

    // Testing only BMP creatinon!
    // BMPcreator(Mert_ertekek_TOMB, Eloallitott_ertekek_DARAB);
    // End of testing

    //A jelenlegi folyamat pid-jének a megtalálása
    int I_Want_Pid=FindPID();
    printf("A pid: %d\n",I_Want_Pid);
    //eddig

    //
    SendViaFile(&Mert_ertekek_TOMB[0],Eloallitott_ertekek_DARAB);
    //

    //
    ReceiveViaFile(0);
    //

    //Működik rendeltetés szerűen minden 03.31 20:50
    return EXIT_SUCCESS;
}



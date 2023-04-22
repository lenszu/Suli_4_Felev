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
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    signal(SIGINT, SignalHandler);
    signal(SIGUSR1, SignalHandler);
    int *Uzemmodok;
    int *Mert_ertekek_TOMB;
    int Eloallitott_ertekek_DARAB = 0;
    Mod_handling(argc, argv, &Uzemmodok);

    ///////////////////////////////////////////////////////////////////
    // ÜZEMMÓD ELDÖNTÉS
    //(*modes)[0] send
    //(*modes)[1] receive
    //(*modes)[2] file
    //(*modes)[3] socket
    ///////////////////////////////////////////////////////////////////

    // KÜLDŐ ÉS FOGADÓ ÜZEMMÓDOK BEÁLLÍTÁSA:
    if (Uzemmodok[1] == 1 && Uzemmodok[3] == 1) // receive - socket
    {
        // készítsük fel a programot a SIGUSR1 jel fogadására, valamint, ha beérkezett a várt jel, akkor a ReceiveViaFile függvényt hívjuk meg
        ReceiveViaSocket();
    }
    else if (Uzemmodok[0] >= 1 && Uzemmodok[3] == 1) // send - socket
    {
        Eloallitott_ertekek_DARAB = Measurement(&Mert_ertekek_TOMB);
        SendViaSocket(&Mert_ertekek_TOMB[0], Eloallitott_ertekek_DARAB);
        free(Mert_ertekek_TOMB);
        return 0;
    }
    else if (Uzemmodok[1] == 1 && Uzemmodok[2] >= 1) // receive - file
    {
        // készítsük fel a programot a SIGUSR1 jel fogadására, valamint, ha beérkezett a várt jel, akkor a ReceiveViaFile függvényt hívjuk meg
        while (1)
        {
            signal(SIGUSR1, ReceiveViaFile);
            pause();
        }
    }
    else if (Uzemmodok[0] >= 1 && Uzemmodok[2] >= 1) // send - file
    {
        Eloallitott_ertekek_DARAB = Measurement(&Mert_ertekek_TOMB);
        SendViaFile(&Mert_ertekek_TOMB[0], Eloallitott_ertekek_DARAB);
        free(Mert_ertekek_TOMB);
        return 0;
    }

    free(Uzemmodok);
    return EXIT_SUCCESS;
}

#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int *Mert_ertekek_TOMB;
    int Eloallitott_ertekek_DARAB = Measurement(&Mert_ertekek_TOMB);
    printf("Az eloallitott darabszam: %d\n", Eloallitott_ertekek_DARAB);
    BMPcreator(Mert_ertekek_TOMB,Eloallitott_ertekek_DARAB);
}
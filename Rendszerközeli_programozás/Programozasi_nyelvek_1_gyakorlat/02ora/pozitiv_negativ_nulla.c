#include <stdio.h>

/*
    Kerjunk be egy egesz szamot, majd dontsuk el, hogy a szam pozitiv, negativ vagy pedig nulla.
*/

int main()
{
    printf("Adj meg egy egesz szamot: ");
    int szam;
    scanf("%d", &szam);

    if (szam > 0)
    {
        printf("A(z) %d pozitiv\n", szam);
    }
    else if (szam < 0)
    {
        printf("A(z) %d negativ\n", szam);
    }
    else if (szam == 0)
    {
        printf("A 0 se nem pozitiv, se nem negativ.\n");
    }

    return 0;
}
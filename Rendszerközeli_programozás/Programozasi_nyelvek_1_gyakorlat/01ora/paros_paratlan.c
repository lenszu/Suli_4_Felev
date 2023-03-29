#include <stdio.h>

//    Kerjunk be egy egesz szamot, majd dontsuk el, hogy paros vagy paratlan.

int main()
{
    printf("Adj meg egy egesz szamot: ");
    int szam;
    scanf("%d", &szam);

    if (szam % 2 == 0)
    {
        printf("A(z) %d paros.\n", szam);
    }
    else
    {
        printf("A(z) %d paratlan.\n", szam);
    }

    return 0;
}
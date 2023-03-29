#include <stdio.h>

//    A program addig olvas be egesz szamokat, amig '0' bemenetet nem kap, ekkor kiirja az addig megadott szamok osszeget.

int main()
{
    int n;
    int osszeg = 0;

    do
    {
        scanf("%d", &n);
        osszeg += n;
    } while (n != 0);

    printf("Az eddig megadott szamok osszege: %d\n", osszeg);

    return 0;
}
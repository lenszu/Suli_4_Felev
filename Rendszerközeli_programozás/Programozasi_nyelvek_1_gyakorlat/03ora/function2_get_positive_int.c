#include <stdio.h>

/*
    Irjunk fuggvenyt, amely addig keri be a szamokat, amig a felhasznalo nem pozitiv egesz szamot ad meg, majd terjen vissza az ertekkel.
*/

int get_positive_int();

int main()
{
    printf("Adj meg egy pozitiv egesz szamot: ");
    printf("A megadott pozitiv egesz szam: %d.\n", get_positive_int());

    return 0;
}

int get_positive_int()
{
    int n;
    scanf("%d", &n);
    while (n < 1)
    {
        printf("Pozitiv egesz szamot adj meg: ");
        scanf("%d", &n);
    }
    return n;
}
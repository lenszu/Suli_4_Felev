#include <stdio.h>

//    Kerjuk be egy teglalap ketto darab oldalat, majd irassuk ki a teglalap keruletet es teruletet.

int main()
{
    printf("Add meg a teglalap egyik oldalat: ");
    int a;
    scanf("%d", &a);

    printf("Add meg a teglalap masik oldalat: ");
    int b;
    scanf("%d", &b);

    int kerulet = 2 * (a + b);
    int terulet = a * b;

    printf("A teglalap kerulete: %d\n", kerulet);
    printf("A teglalap terulete: %d\n", terulet);

    return 0;
}
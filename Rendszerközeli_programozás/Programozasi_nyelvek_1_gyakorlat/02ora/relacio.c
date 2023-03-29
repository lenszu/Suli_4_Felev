#include <stdio.h>

/*
    A program beker 2 db egesz szamot, majd a megfelelo relacios jellel kiirja a kettejuk kozotti viszonyt.
*/

int main()
{
    printf("Add meg az elso szamot: ");
    int a;
    scanf("%d", &a);

    printf("Add meg a masodik szamot: ");
    int b;
    scanf("%d", &b);

    if (a > b)
    {
        printf("%d > %d", a, b);
    }
    else if (a < b)
    {
        printf("%d < %d", a, b);
    }
    else
    {
        printf("%d = %d", a, b);
    }

    return 0;
}
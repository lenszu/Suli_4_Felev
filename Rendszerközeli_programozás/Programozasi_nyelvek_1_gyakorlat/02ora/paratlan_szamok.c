#include <stdio.h>

/*
    A program beker egy pozitiv egesz szamot, majd kiirja 0 es a szam kozotti paratlan szamokat, csokkeno sorrendben. (zart intervallum)
*/

int main()
{
    printf("Add meg a szamot: ");
    int n;
    scanf("%d", &n);

    for (int i = n; i > 0; i--)
    {
        if (i % 2 == 1)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
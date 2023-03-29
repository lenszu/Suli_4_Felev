#include <stdio.h>

/*
    A program beker egy egesz szamot, majd kiirja 1-tol a szamig (zart intervallum) a 4-gyel oszthato szamokat.
*/

int main()
{
    printf("Add meg a szamot: ");
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        if (i % 4 == 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
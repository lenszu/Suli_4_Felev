#include <stdio.h>

/*
    Szamoljuk ki az egesz szamok osszeget 1-100 zart intervallumon.
*/

int main()
{
    int osszeg = 0;

    for (int i = 1; i <= 100; ++i)
    {
        osszeg += i;
    }

    printf("%d\n", osszeg);

    return 0;
}
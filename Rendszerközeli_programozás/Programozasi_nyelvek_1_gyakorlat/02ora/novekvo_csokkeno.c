#include <stdio.h>

/*
    Irassuk ki a szamokat 0-10 zart intervallumon.
*/

int main()
{
    for (int i = 0; i <= 10; ++i)
    {
        printf("%d\n", i);
    }

    // Irassuk ki csokkeno sorrendben a pozitiv szamokat a 0-10 zart intervallumon.

    for (int i = 10; i >= 0; i -= 2)
    {
        printf("%d\n", i);
    }

    return 0;
}
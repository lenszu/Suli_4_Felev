#include <stdio.h>

/*
    Szamoljuk ki az 1000-nel kisebb szamok osszeget, melyek oszthatók 3-mal VAGY 5-tel.
*/

int main()
{
    int osszeg = 0;

    for (int i = 0; i < 1000; ++i)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            osszeg += i;
        }
    }

    printf("%d\n", osszeg);

    return 0;
}
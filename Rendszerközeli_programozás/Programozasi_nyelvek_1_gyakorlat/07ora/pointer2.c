#include <stdio.h>

// Egy eljaras segitsegevel csereljuk fel 2 db egesz tipusu valtozo erteket.

void csere(int *a, int *b);

int main()
{
    int a = 5;
    int b = 7;

    printf("%d %d\n", a, b);

    csere(&a, &b);

    printf("%d %d\n", a, b);

    return 0;
}

void csere(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;

    /*
     Segedvaltozo nelkül
     *a += *b;
     *b = *a - *b;
     *a -= *b;
     */
}
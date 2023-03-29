#include <stdio.h>

int main()
{
    int a = 5;
    printf("A(z) \"a\" valtozo erteke:\t%d.\n", a);
    printf("A(z) \"a\" valtozo memoriacime:\t%p.\n", &a);

    int *pa = &a;
    puts("---");
    printf("A(z) \"pa\" mutato memoriacime:\t%p.\n", &pa);
    printf("A(z) memoriacim, amire a \"pa\" mutato mutat:\t%p.\n", pa);
    printf("A(z) memoriacimen talalhato ertek, amire a \"pa\" mutato mutat:\t%d.\n", *pa);

    int **ppa = &pa;
    puts("---");
    printf("A(z) \"ppa\" mutato memoriacime:\t%p.\n", &ppa);
    printf("A(z) memoriacim, amire a \"ppa\" mutato mutat:\t%p.\n", ppa);
    printf("A(z) memoriacimen talalhato ertek, amire a \"ppa\" mutato mutat:\t%d.\n", **ppa);
    return 0;
}

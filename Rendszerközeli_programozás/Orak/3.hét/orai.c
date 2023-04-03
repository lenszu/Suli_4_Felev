#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int bit_osszeg(int elso, int masodik)
{
    //*((int*)(&x))
}

int fuggveny(int N)
{
    // bitmuvelettel kell a szamot 1-el novelni
    // keressuk az elso nullat. ha megvan akkor a hata mogott levo 1-eseket nullara valtjuk, a megtalalt 0-at 1-esre, aztan a tobbit meg hagyjuk
    int M = 1;
    while (N & M)
    {
        N &= ~M;
        M <<= 1;
        // xor-al tudunk torolni
    }
    return M | N;
}
int fuggveny_sajat(int s)
{
    //-1 szeresét kell visszaadja
    return fuggveny(~s);
}

void eljaras_1(int szam)
{
    int i;

    for (i = 31; i >= 0; i--)
    {
        if (szam & (1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    puts("");
    printf("%d\n", szam);
}

void eljaras_2(int szam)
{
    unsigned int M = 1 << (sizeof(int) * 8 - 1); // 31
    while (M)
    {
        printf("%d", szam & M ? 1 : 0);
        M >>= 1;
    }
    puts("");
}

int main(int argc, char *argv[], char *env[])
{
    // bit műveletek
    // eljárás, paraméter 1 int, kiiratja ennek a paraméterének, a bináris reprezentációját (32 bites)

    int szam = 0;
    printf("Kérem a számot: ");
    scanf("%d", &szam);
    // eljaras_1(szam);
    // eljaras_2(szam);
    szam = fuggveny(szam);
    printf("%d\n", szam);

    // szam = fuggveny_sajat(szam);
    printf("%d", szam);
    return EXIT_SUCCESS;
}
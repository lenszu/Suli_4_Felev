#include <stdio.h>

/*
    Irjunk egy fuggvenyt, amely kap egy EGESZ szamot (negativ egesz szamok, 0, pozitiv egesz szamok), majd 1-gyel ter vissza, ha a szam prim, 0-val, ha a szam NEM prim.
    Tajekoztassuk a felhasznalot az eredmenyrol.
*/

int if_prime(int n);

int main()
{
    printf("Add meg a szamot: ");
    int n;
    scanf("%d", &n);
    if (if_prime(n) == 1)
    {
        printf("%d prim szam.\n", n);
    }
    else
    {
        printf("%d nem prim szam.\n", n);
    }

    return 0;
}

int if_prime(int n)
{
    if (n < 2) // A 2 a legkisebb primszam, minden ami kisebb tole nem prim (a negativ szamok is lekezelve).
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else if (n % 2 == 0) // A 2-n kivul nem letezik paros primszam.
    {
        return 0;
    }
    else
    {
        for (int i = 3; i < n / 2; i += 2)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}
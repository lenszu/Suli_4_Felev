#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool if_prime_good(int n);
bool if_prime_wrong(int n);

// 10.000-ig 1229 db a helyes eredmeny

int main()
{
    int counter1 = 0;
    int counter2 = 0;
    int limit = 10000;

    for (int i = 1; i <= limit; i++)
    {
        if (if_prime_good(i))
        {
            counter1++;
        }
        if (if_prime_wrong(i))
        {
            counter2++;
        }
    }
    printf("Az if_prime_good:\t%d db primet talalt.\n", counter1);
    printf("Az if_prime_wrong:\t%d db primet talat\n", counter2);

    return 0;
}

bool if_prime_good(int n)
{
    if (n < 2)
    {
        return false;
    }
    else if (n == 2)
    {
        return true;
    }
    else if (n % 2 == 0)
    {
        return false;
    }
    else
    {
        for (int i = 3; i <= sqrt(n); i += 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

bool if_prime_wrong(int n)
{
    if (n < 2)
    {
        return false;
    }
    else if ((n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0))
    {
        return false;
    }
    else
    {
        return true;
    }
}
#include <stdio.h>

/*
    irjunk egy fuggvenyt, ami egy egesz szamot var, majd a szam duplajaval ter vissza.
*/

int duplaz(int number);

int main()
{
    printf("Add meg a szamot, amit duplazni szeretnel: ");
    int n;
    scanf("%d", &n);

    printf("A szam duplaja: %d\n", duplaz(n));

    return 0;
}

int duplaz(int number)
{
    int result = number * 2;
    return result; // return number*2;
}
#include <stdio.h>

/*
    Irassuk a kepernyore otszor, hogy "Hello".
*/

int main()
{
    int k = 0;
    do
    {
        printf("Hello\n");
        ++k;
    } while (k < 5);

    /*
    int j = 0;
    while (j < 5)
    {
        printf("Hello\n");
        ++j;
    }
    */

    /*
    for (int i = 0; i < 5; ++i)
    {
        printf("Hello\n");
    }
    */
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

/*
    Irj programot, ami beleirja a neved a name.txt nevu fajlba.
*/

int main(void)
{
    FILE *fp = fopen("name.txt", "w");
    if (fp == NULL)
    {
        printf("Hiba a fajl megnyitasa kozben.\n");
        return 1;
    }

    fprintf(fp, "Vezeteknev Keresztnev");

    return EXIT_SUCCESS;
}

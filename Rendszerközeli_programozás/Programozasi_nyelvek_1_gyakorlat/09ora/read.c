#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
    Irj programot, ami a name.txt nevu allomanybol kiolvassa a mar benne levo neved, majd kiirja a kepernyore csupa nagybetuvel.
*/

int main(void)
{
    FILE *fp = fopen("name.txt", "r");
    if (fp == NULL)
    {
        printf("Hiba a fajl megnyitasa kozben.\n");
        return 1;
    }

    char name[1000];

    fgets(name, 1000, fp);

    for (int i = 0; i < strlen(name); i++)
    {
        printf("%c", toupper(name[i]));
    }
    fclose(fp);

    return EXIT_SUCCESS;
}

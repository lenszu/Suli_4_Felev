#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Irj programot, ami a lines.txt allomanyba irja az "eleg" szoig a billentyuzetrol (standard input) megadott sorokat.
    Ezt kovetoen irja ki az osszes megadott sort, es tajekoztassa a felhasznalot, hogy hany sor talalhato az allomanyban.
*/

#define SIZE 1000

int main(void)
{
    FILE *fp = fopen("lines.txt", "w");
    if (fp == NULL)
    {
        printf("Hiba a fajl megnyitasa kozben.\n");
        return 1;
    }

    char line[SIZE];
    fgets(line, SIZE, stdin);
    line[strlen(line) - 1] = '\0';

    while (strcmp(line, "eleg") != 0)
    {
        fprintf(fp, "%s\n", line);
        fgets(line, SIZE, stdin);
        line[strlen(line) - 1] = '\0';
    }
    fclose(fp);

    puts("");
    int line_counter = 0;
    FILE *fpr = fopen("lines.txt", "r");
    if (fpr == NULL)
    {
        printf("Hiba a fajl megnyitasa kozben.\n");
        return 1;
    }

    while (fgets(line, SIZE, fpr) != NULL)
    {
        printf("%s", line);
        line_counter++;
    }
    printf("Az allomanyban %d db sor talalhato.\n", line_counter);
    fclose(fpr);

    return EXIT_SUCCESS;
}

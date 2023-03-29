#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Irj programot, ami minden futas soran pontosan egy darab random szamot fuz hozza (soronkent egyet) a random_numbers.txt allomanyhoz.
    1 - 100 zart intervallumbol
*/

int random_number_generator(const int lower, const int upper);

int main(void)
{
    srand(time(NULL));

    FILE *fp = fopen("random_numbers.txt", "a");
    if (fp == NULL)
    {
        printf("Hiba a fajl megnyitasa kozben.\n");
        return 1;
    }

    fprintf(fp, "%d\n", random_number_generator(1, 100));
    fclose(fp);

    return EXIT_SUCCESS;
}

int random_number_generator(const int lower, const int upper)
{
    return rand() % (upper - lower + 1) + lower;
}
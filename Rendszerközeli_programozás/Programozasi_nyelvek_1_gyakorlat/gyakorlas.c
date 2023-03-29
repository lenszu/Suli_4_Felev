#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
    A program addig olvas be egesz szamokat, amig '0' bemenetet nem kap.
    Kozben szamolja, hogy hany pozitiv illetve negativ szam erkezett be.
    A '0' bement utan kiirja ezek darabszamat.
*/

int main(int argc, char *argv[], char *env[])
{
    // int poz_ossz = 0, neg_ossz = 0;
    // printf("Adjon meg egy szamot!(0-ra leall): ");
    // int be = scanf("%d", &be);

    // while (be != 0)
    // {
    //     if (be > 0)
    //     {
    //         poz_ossz++;
    //     }
    //     else if (be < 0)
    //     {
    //         neg_ossz++;
    //     }
    //     printf("Egy kovetkezo szamot: ");
    //     scanf("%d", &be);
    // }

    // printf("A pozitiv szamok: \"%d\"\nA negativ szamok: \"%d\"\n", poz_ossz, neg_ossz);
    //////////////////////////////////////////////////////////////////////////////////

    /*
    A program beker egy egesz szamot, majd kiirja 1-tol a szamig (zart intervallum) a 4-gyel oszthato szamokat.
*/
    // int be = 0;
    // printf("Adjon meg egy szamot: ");
    // scanf("%d", &be);

    // for (int i = 1; i <= be; i++)
    // {
    //     if (i % 4 == 0)
    //     {
    //         printf("%d ", i);
    //     }
    // }

    /*
    Szamoljuk ki az 1000-nel kisebb szamok osszeget, melyek oszthatók 3-mal VAGY 5-tel.
    */

    // int osszeg = 0;

    // for (int i = 0; i < 1000; i++)
    // {
    //     if (i % 3 == 0 || i % 5 == 0)
    //     {
    //         osszeg += i;
    //     }
    // }

    // printf("%d", osszeg);

    // int a = 2;

    // int b = duplaz(a);

    // printf("%d", b);

    // int tomb[] = {1, 2, 3, 4, 5};
    // int i = 0;
    // printf("%d", sizeof(tomb) / sizeof(tomb[0]));
    // // for (int i = 0; i < sizeof(tomb); i++)
    // // {
    // //     printf("%d", tomb[i]);
    // // }

    // char elso[] = "Sziasztok guys";
    // char masodik[strlen(elso)];

    // strcpy(masodik, elso);
    // int i = 0;
    // while (elso[i] != '\0')
    // {
    //     printf("%c", elso[i]);
    //     i++;
    // }
    // puts("");
    // if (strcmp(elso, masodik) == 1)
    // {
    //     printf("Ezek megegyeznek\n");
    // }
    // else
    // {
    //     printf("Nincs kulonbseg\n");
    // }

    // srand(time(NULL));
    // int a, b;
    // printf("Adjon meg ket szamot space-el elvalasztva(felso also): ");
    // scanf("%d %d", &a, &b);

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d ", random_number_generator(a, b));
    // }

    int *p = (int *)malloc(100 * sizeof(int));
    p = (int *)calloc(101, sizeof(int));

    return EXIT_SUCCESS;
}

// int random_number_generator(int felso, int also)
// {
//     return rand() % (felso - also + 1) + also;
// }

// int duplaz(int a){
//     return a*2;
// }
#include <stdio.h>

/*
    Beker egy egesz szamot, majd a szammal azonos magassagu derekszogu haromszoget irat a kepernyore, ahol a derekszog bal alul talalhato.
    (Mario lepcsoje)
*/

int main()
{
    printf("Add meg a haromszog magassagat: ");
    int height;
    scanf("%d", &height);

    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
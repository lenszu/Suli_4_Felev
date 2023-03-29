#include <stdio.h>

/*
    Beker egy egesz szamot, majd a szammal azonos magassagu derekszogu haromszoget irat a kepernyore, ahol a derekszog jobb alul talalhato.
    (Mario lepcsoje)
*/

int main()
{
    printf("Add meg a haromszog magassagat: ");
    int height;
    scanf("%d", &height);

    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
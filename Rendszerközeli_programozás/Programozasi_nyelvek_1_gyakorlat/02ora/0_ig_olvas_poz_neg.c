#include <stdio.h>

/*
    A program addig olvas be egesz szamokat, amig '0' bemenetet nem kap.
    Kozben szamolja, hogy hany pozitiv illetve negativ szam erkezett be.
    A '0' bement utan kiirja ezek darabszamat.
*/

int main()
{
    int n;
    int pozitiv_db = 0;
    int negativ_db = 0;

    do
    {
        scanf("%d", &n);
        if (n > 0)
        {
            pozitiv_db++;
        }
        else if (n < 0)
        {
            negativ_db++;
        }
    } while (n != 0);

    printf("Pozitiv szamok darabszama: %d\n", pozitiv_db);
    printf("Negativ szamok darabszama: %d\n", negativ_db);

    return 0;
}
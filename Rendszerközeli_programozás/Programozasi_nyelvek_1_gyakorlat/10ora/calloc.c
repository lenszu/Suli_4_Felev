#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *parray;

    printf("Add meg hany elemu tombot szeretnel: ");
    scanf("%d", &n);

    parray = (int *)calloc(n, sizeof(int));
    if (parray == NULL)
    {
        printf("Hiba a memória lefoglalása közben.\n");
        exit(0);
    }

    printf("A tomb elemei kezdetben:");
    printf(" %d", *(parray));
    for (int i = 1; i < n; i++)
    {
        printf(", %d", *(parray + i));
    }
    puts(".");

    puts("Add meg a tomb elemeit.");
    for (int i = 0; i < n; i++)
    {
        printf("%d/%d: ", i + 1, n);
        scanf("%d", parray + i);
    }

    printf("A tomb elemei feltoltes utan: ");
    printf("%d", *parray);
    for (int i = 1; i < n; i++)
    {
        printf(", %d", *(parray + i));
    }
    puts(".");

    free(parray);

    return 0;
}
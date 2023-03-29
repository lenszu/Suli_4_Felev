#include <stdio.h>
#include <stdlib.h>

int main()
{
    int buffer, index = 0;
    int *pnumbers = malloc(1 * sizeof(int));

    printf("Irj be egesz szamokat (0 vege):\n");
    printf("Kerem a(z) 1. szamot: ");
    scanf("%d", &buffer);

    while (buffer != 0)
    {
        pnumbers[index] = buffer;
        index++;
        pnumbers = (int *)realloc(pnumbers, (index + 1) * sizeof(int));
        printf("Kerem a(z) %d. szamot: ", index + 1);
        scanf("%d", &buffer);
    }

    puts("");
    printf("A megadott szamok:\n");
    for (int i = 0; i < index; ++i)
    {
        printf("%d/%d: %d\n", i + 1, index, pnumbers[i]);
    }
    free(pnumbers);
    return 0;
}
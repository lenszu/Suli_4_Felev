#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    A program "vege" szoig olvas be sorokat a billentyuzetrol, dinaimkus memoriafoglalat hasznalva
*/

#define SIZE 1024

int main(void)
{
    char buffer[SIZE];
    int index = 0;
    char **plines = (char **)malloc(0 * sizeof(char *));

    printf("Adj meg szovegeket \"vege\"-ig:\n");
    printf("Kerem a(z) 1. szoveget: ");
    fgets(buffer, SIZE, stdin);
    buffer[strlen(buffer) - 1] = '\0';

    while (strcmp(buffer, "vege") != 0)
    {
        plines[index] = (char *)malloc(strlen(buffer) * sizeof(char));
        strcpy(plines[index], buffer);
        index++;
        plines = realloc(plines, (index + 1) * sizeof(char *));

        printf("Kerem a(z) %d. szoveget: ", index + 1);
        fgets(buffer, SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';
    }

    puts("");
    printf("A megadott sorok:\n");
    for (int i = 0; i < index; i++)
    {
        printf("%d/%d: %s\n", i + 1, index, plines[i]);
    }

    for (int i = 0; i < index; i++)
    {
        free(plines[i]);
    }
    free(plines);

    return EXIT_SUCCESS;
}

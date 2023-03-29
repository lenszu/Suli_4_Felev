#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char line[] = "alma banan citrom dinnye eper";
    char *pline;

    pline = strtok(line, " ");
    while (pline != NULL)
    {
        printf("%s\n", pline);
        pline = strtok(NULL, " ");
    }

    return EXIT_SUCCESS;
}

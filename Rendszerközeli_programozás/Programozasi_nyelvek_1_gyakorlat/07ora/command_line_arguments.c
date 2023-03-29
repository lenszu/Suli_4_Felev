#include <stdio.h>

// Irassuk ki a megadott parancssori argumentumokat.

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Nem adtal meg parancssori argumentumot.\n");
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            printf("A(z) %d. parancssori argumentum: %s\n", i, argv[i]);
        }
    }

    return 0;
}

#include <stdio.h>

/*
    Irassuk ki a szamokat 0-10 kozott (zart intervallumon) es nezzük meg mit csinal a "break" es a "continue" a ciklusokban.
*/

int main()
{
    printf("sima:");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", i);
    }
    printf("\nbreak:");

    for (int i = 0; i <= 10; i++)
    {
        if (i == 5)
        {
            break; // Azonnal befejezi az egesz ciklust.
        }
        printf(" %d", i);
    }
    printf("\ncontinue:");

    for (int i = 0; i <= 10; i++)
    {
        if (i == 5)
        {
            continue; // Csak az aktualis iteraciot hagyja ki.
        }
        printf(" %d", i);
    }

    return 0;
}
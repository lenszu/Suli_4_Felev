#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int random_general(int felso, int also);

// Keresofa
typedef struct ize
{
    int adat;
    struct ize *bal, *jobb;
} ELEM;

// Elem beszúrása
void Beszur(int d, ELEM **H)
{
    if (*H == NULL)
    {
        *H = malloc(sizeof(ELEM));
        (**H).adat = d;
        (**H).bal = NULL;
        (**H).jobb = NULL;
    }
    else
    {
        if ((**H).adat > d)
        {
            Beszur(d, &(**H).bal);
        }
        else
        {
            Beszur(d, &(**H).jobb);
        }
    }
}

// Bejárás, INORDER
void Bejar(ELEM *H)
{
    if (H != NULL)
    {
        Bejar((*H).bal);
        printf("%d ", (*H).adat);
        Bejar((*H).jobb);
    }
}

int main(int argc, char *argv[], char *env[])
{
    // rendezett bináris fa, jobbra nagyobb balra kisebb
    // Kell egy fej, amely egy pointer, és mutat az első elemre. Ha a fej, amire mutat NULL értékű, akkor a fa üres.
    ELEM *fej = NULL;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        Beszur(random_general(10, 0), &fej);
    }
    Bejar(fej);
    return EXIT_SUCCESS;
}

int random_general(int felso, int also)
{
    return rand() % (felso - also + 1) + also;
}
#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void vissza(int **argv, int size)
{
    (*argv) = calloc(6, sizeof(int));
    (*argv)[0]=6;
    for (int i = 0; i < size; i++)
    {
        printf("%d ", (*argv)[i]);
    }
    printf("\n A merete: %d\n", size);
}

int main(int argc, char *argv[])
{
    int *Mert_ertekek_TOMB;
    int merete = 6;
    vissza(&Mert_ertekek_TOMB, merete);
    // for (int i = 0; i < merete; i++)
    // {
    //     printf("%d ",Mert_ertekek_TOMB[i]);
    // }
    free(Mert_ertekek_TOMB);
}
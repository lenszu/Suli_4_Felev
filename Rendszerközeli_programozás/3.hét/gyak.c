#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[], char *env[])
{
    int tmp = 0;
    int c = 33 ^ 17; // 33=00100001 17=00010001
    int szam = 122;  // 122= 0111 1010
    for (int i = 7; i >= 0; i--)
    {
        tmp = 1 << i;
        printf("%d: ", tmp);
        if (96 & tmp)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    int e = 96 >> 1; // 
    printf("%d", e);
    // printf("%d", szam | 4); // 12=00001100
    return EXIT_SUCCESS;
}
/*** Example of time handling ***/
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

// Change the pointer of the array
// void change(int **array, int length)
// {
//     *array = malloc(length * sizeof(int));
//     if (*array == NULL)
//         return;
//     for (int i = 0; i < length; i++)
//         (*array)[i] = 1;
// }
int main()
{
    srand(time(NULL));
    int b[6] = {0, 0, 0, 0, 0, 0};
    double rf = 0;
    for (int i = 0; i < 6; i++)
    {
        rf = (double)rand() / ((unsigned)RAND_MAX + 1); // 0.0 <= y < 1.0
        if (rf <= 0.428571)
            b[i] = 1;
        else if (rf > 0.428571 && rf <= 0.783409)
        {
            b[i] = -1;
        }
        else
        {
            b[i] = 0;
        }
        printf("%d ", b[i]);
    }
    return 0;
}
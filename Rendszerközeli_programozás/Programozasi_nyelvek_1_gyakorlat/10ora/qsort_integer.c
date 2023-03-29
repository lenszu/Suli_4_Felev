#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fill_array(int size, int array[]);
void printf_array(int size, int array[]);
int compare_integer(const void *a, const void *b);

int main(void)
{
    srand(time(NULL));

    int array[SIZE];
    fill_array(SIZE, array);

    printf("A tomb elemei:");
    printf_array(SIZE, array);

    qsort(array, SIZE, sizeof(array[0]), compare_integer);
    printf("A tomb elemei rendezes utan:");
    printf_array(SIZE, array);

    return EXIT_SUCCESS;
}

void fill_array(int size, int array[])
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100 + 1;
    }
}

void printf_array(int size, int array[])
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n");
}

int compare_integer(const void *a, const void *b)
{
    int a_integer = *(int *)a;
    int b_integer = *(int *)b;
    return a_integer - b_integer; // novekvo sorrend
    // return b_integer - a_integer; // csokkeno sorrend
}

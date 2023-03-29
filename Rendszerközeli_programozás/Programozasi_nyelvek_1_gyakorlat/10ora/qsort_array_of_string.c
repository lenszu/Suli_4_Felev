#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printf_array(int size, char *array[]);
int sort_array(const void *a, const void *b);

int main(void)
{

    char *array[] = {"eper", "banan", "dinnye", "citrom", "alma"};
    printf("A tomb elemei:");
    printf_array(5, array);

    qsort(array, 5, sizeof(array[0]), sort_array);
    printf("A tomb elemei rendezes utan:");
    printf_array(5, array);

    return EXIT_SUCCESS;
}

void printf_array(int size, char *array[])
{
    for (int i = 0; i < size; i++)
    {
        printf(" %s", array[i]);
    }
    printf("\n");
}

int sort_array(const void *a, const void *b)
{
    char *a_string = *(char **)a;
    char *b_string = *(char **)b;
    return strcmp(a_string, b_string); // novekvo sorrend
    // return strcmp(b_string, a_string);  // csokkeno sorrend
}

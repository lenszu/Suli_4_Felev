#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int min;
    int max;
    double average;
} Elements_of_array;

int random_number_generator(int lower, int upper);
Elements_of_array array_examiner(int array[], int size);

int main(void)
{
    srand(time(NULL));

    int size = 10;
    int basic_array[size];
    basic_array[0] = random_number_generator(10, 99);
    printf("A tomb elemei: %d", basic_array[0]);

    for (int i = 1; i < size; i++)
    {
        basic_array[i] = random_number_generator(10, 99);
        printf(", %d", basic_array[i]);
    }
    printf("\n");

    Elements_of_array examined_array = array_examiner(basic_array, size);

    printf("Legkisebb elem: %d\n", examined_array.min);
    printf("Legnagyobb elem: %d\n", examined_array.max);
    printf("Az elemek atlaga: %.1lf\n", examined_array.average);

    return EXIT_SUCCESS;
}

int random_number_generator(int lower, int upper)
{
    return rand() % (upper - lower + 1) + lower;
}

Elements_of_array array_examiner(int array[], int size)
{
    Elements_of_array tmp_array;
    tmp_array.average = array[0];
    tmp_array.min = array[0];
    tmp_array.max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] < tmp_array.min)
        {
            tmp_array.min = array[i];
        }
        if (array[i] > tmp_array.max)
        {
            tmp_array.max = array[i];
        }
        tmp_array.average += array[i];
    }
    tmp_array.average /= size;

    return tmp_array;
}

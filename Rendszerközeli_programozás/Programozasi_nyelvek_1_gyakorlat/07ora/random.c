#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  Generaljunk N db random szamot a felhasznolotol bekert zart intervallumon.

int random_number_generator(int lower, int upper);

int main()
{
    const int N = 10;
    srand(time(NULL));
    
    printf("Add meg az intervallum also hatarat: ");
    int lower;
    scanf("%d", &lower);

    printf("Add meg az intervallum felso hatarat: ");
    int upper;
    scanf("%d", &upper);

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", random_number_generator(lower, upper));
    }

    return 0;
}

int random_number_generator(const int lower, const int upper)
{
    return rand() % (upper - lower + 1) + lower;
}
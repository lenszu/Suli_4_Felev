#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int matrix[6][5] = {    // az elso dimenziot nem kötelezo megadni, igy is mukodik: matrix[][5]
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
    };

    printf("%d\n", matrix[0][4]);

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//    A felhasznalotol kerjuk be a matrix meretet (sor, oszlop azonos), toltsuk fel a matrixot random szamokkal 1 es 99 kozott (zart intervallum, minden futtatas soran mas), majd irassuk ki a matrixot, tabulatorral elvalasztva (a vegen ne legyen felesleges tabulator)

int random_number_generator(int lower, int upper);
void print_matrix(int row, int column, int matrix[row][column]);

int main(void)
{
    srand(time(NULL)); // ugyanez nem az idovel, hanem 2022-vel: srand(2022);
    printf("Add meg, a matrix sor es egyben oszlopszamat: ");
    int n;
    scanf("%d", &n);

    int matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = random_number_generator(1, 99);
        }
    }
    print_matrix(n, n, matrix);

    return EXIT_SUCCESS;
}

int random_number_generator(int lower, int upper)
{
    return rand() % (upper - lower + 1) + lower;
}

void print_matrix(int row, int column, int matrix[row][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
}
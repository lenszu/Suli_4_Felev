#include <stdio.h>
#include <stdbool.h>

void kiir(int size, int array[]);
int sum(int size, int array[]);
double avarage(int size, int array[]);
void reverse(int size, int array[]);
bool is_palindrome(int size, int array[]);
bool contains(int size, int array[], int looked_for);
int maximum_value_of_the_array(int size, int array[]);

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    int size = 5; // int size = sizeof(array) / sizeof(int);
    printf("Elso feladat:\n");
    kiir(size, array);

    printf("\nMasodik feladat:\n");
    printf("A tomb eleminek az osszege: %d\n", sum(size, array));

    printf("\nHarmadik feladat:\n");
    printf("A tomb eleminek az atlaga: %.2lf\n", avarage(size, array));

    printf("\nNegyedik feladat:\n");
    printf("A megforditott tomb:\n");
    reverse(size, array);
    kiir(size, array);

    printf("\nOtodik feladat:\n");
    if (is_palindrome(size, array) == true) // if(if_palindrome)
    {
        printf("A tomb palindrom.\n");
    }
    else
    {
        printf("A tomb nem palindrom.\n");
    }

    printf("\nHatodik feladat:\n");
    printf("A tomb maximuma: %d\n", maximum_value_of_the_array(size, array));

    printf("\nHetedik feladat:\n");
    int looked_for = 2;
    if (contains(size, array, looked_for))
    {
        printf("A(z) %d benne van a tombben.\n", looked_for);
    }
    else
    {
        printf("A(z) %d nincs benne van a tombben.\n", looked_for);
    }

    return 0;
}

void kiir(int size, int array[])
{
    // Irassuk ki a tomb elemeit. (soronkent egy elemet)
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
}

int sum(int size, int array[])
{
    // Adjuk vissza a tomb elemeinek az osszeget.
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        counter += array[i];
    }
    return counter;
}

double avarage(int size, int array[])
{
    // Adjuk vissza a tomb elemeinek az atlagat.
    double counter = 0;
    for (int i = 0; i < size; i++)
    {
        counter += array[i];
    }
    return counter / size;
}

void reverse(int size, int array[])
{
    // Forditsuk meg a tomb elemeinek a sorrendjet.
    for (int i = 0; i <= size / 2; i++)
    {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

bool is_palindrome(int size, int array[])
{
    // Dontsuk el, hogy a tomb palindrom-e.
    for (int i = 0; i < size; i++)
    {
        if (array[i] != array[size - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int maximum_value_of_the_array(int size, int array[])
{
    // Adjuk vissza a tombben szereplo legnagyobb elem erteket.
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

bool contains(int size, int array[], int looked_for)
{
    // Dontsuk el, hogy a keresett elem megtalalhato-e a tombben.
    for (int i = 0; i < size; i++)
    {
        if (array[i] == looked_for)
        {
            return true;
        }
    }
    return false;
}

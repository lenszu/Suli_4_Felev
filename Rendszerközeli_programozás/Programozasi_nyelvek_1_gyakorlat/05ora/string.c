#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int lenght_of_string(char array[]);

bool is_palindrome_string(int size, char array[]);

bool contains(int size, char array[], char looked_for);

int main()
{
    char *array = "abcdedcba";

    printf("Az 1. feladat.\n");
    printf("A string hossza sajat fugvennyel:  %d, beepitettel: %d.\n", lenght_of_string(array), strlen(array));

    printf("A 2. feladat.\n");
    int size = strlen(array);
    if (is_palindrome_string(size, array))
    {
        printf("A string palindrom.\n");
    }
    else
    {
        printf("A string nem palindrom.\n");
    }

    printf("A 3. feladat.\n");
    char looked_for = 'c';
    if (contains(size, array, looked_for))
    {
        printf("A string tartalmazza a(z) \'%c\' karaktert.\n", looked_for);
    }
    else
    {
        printf("A string nem tartalmazza a(z) \'%c\' karaktert.\n", looked_for);
    }

    return 0;
}

int lenght_of_string(char array[])
{
    int i = 0;
    while (array[i] != '\0')
    {
        i++;
    }
    return i;
}

bool is_palindrome_string(int size, char array[])
{
    for (int i = 0; i < size / 2; i++)
    {
        if (array[i] != array[size - 1 - i])
        {
            return false;
        }
    }
    return true;
}

bool contains(int size, char array[], char looked_for)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == looked_for)
        {
            return true;
        }
    }
    return false;
}

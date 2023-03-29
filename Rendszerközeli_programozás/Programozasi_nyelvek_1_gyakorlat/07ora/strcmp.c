#include <stdio.h>
#include <string.h>

// Dontsuk el ketto db stringrol, hogy  lexikografikus sorrendben (abc sorrend) melyik all elorebb.

int main()
{
    char *first_string = "alma";
    char *second_string = "aalma";

    int strcmp_result = strcmp(first_string, second_string);

    if (strcmp_result < 0)
    {
        printf("Lexikografikusan az elso string all elorebb.\n");
    }
    else if (strcmp_result > 0)
    {
        printf("Lexikografikusan a masodik string all elorebb.\n");
    }
    else
    {
        printf("A ket string megegyezik\n");
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

// Masoljuk at a stringet egy karakter tombbe.

int main()
{
    char first_string[] = "Programozasi nyelvek 1.";
    char second_string[50];
    strcpy(second_string, first_string);

    for (int i = 0; i < strlen(second_string); i++)
    {
        printf("%c", second_string[i]);
    }
    puts("");

    return 0;
}

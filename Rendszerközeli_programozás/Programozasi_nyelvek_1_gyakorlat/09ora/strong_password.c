#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
    char password[102]; // 100 hasznos karakter fer bele (101. sortores, 102. \0)
    printf("Adj meg jelszavakat '*' vegjelig!\n");

    do
    {
        printf("\n");
        fgets(password, sizeof(password), stdin);
        password[strlen(password) - 1] = '\0'; // kommenteld ki ezt a sort es probald ki kilep-e a program a '*' karakterrel

        if (strlen(password) < 8)
        {
            printf("gyenge jelszo\n");
        }
        else
        {
            bool contains_lower; // C-ben alapertelmezetten false erteket vesz fel a bool tipus
            bool contains_upper;
            bool contains_digit;

            for (int i = 0; i < strlen(password); i++)
            {
                if (islower(password[i]))
                {
                    contains_lower = true;
                }
                if (isupper(password[i]))
                {
                    contains_upper = true;
                }
                if (isdigit(password[i]))
                {
                    contains_digit = true;
                }
            }
            if (contains_lower && contains_upper && contains_digit)
            {
                printf("eros jelszo\n");
            }
        }
    } while (strcmp(password, "*") != 0);

    return EXIT_SUCCESS;
}

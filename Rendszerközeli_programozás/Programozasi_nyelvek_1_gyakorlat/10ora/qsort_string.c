#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int compare_char(const void *a, const void *b);

int main(void)
{
    char string[] = "almafa";
    printf("A string rendezes elott: %s\n", string);

    qsort(string, strlen(string), sizeof(string[0]), compare_char);
    printf("A string rendezes utan: %s\n", string);

    return EXIT_SUCCESS;
}

int compare_char(const void *a, const void *b)
{
    char a_char = *(char *)a;
    char b_char = *(char *)b;
    return a_char - b_char; // novekvo sorrend
    // return b_char - a_char; // csokkeno sorrend
}

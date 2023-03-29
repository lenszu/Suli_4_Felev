#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

typedef struct
{
    char name[101];
    int age;
    char sex;
} Person;

int compare_struct(const void *a, const void *b);
void printf_struct_array(Person person_array[], int number_of_people);

int main(void)
{
    printf("Kerem a szemelyeket tartalmazo fajl nevet kiterjesztessel: ");
    char file_name[101];
    fgets(file_name, 101, stdin);
    file_name[strlen(file_name) - 1] = '\0';

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("Hiba a fajl megnyitasa kozben!\n");
        return 1;
    }

    char buffer[SIZE];
    char *pbuffer;
    int line_counter = 0;
    while (fgets(buffer, SIZE, fp) != NULL)
    {
        line_counter++;
    }
    rewind(fp);

    Person persons[line_counter];

    for (int i = 0; i < line_counter; i++)
    {
        fgets(buffer, SIZE, fp);
        char *pbuffer = strtok(buffer, ":");
        strcpy(persons[i].name, pbuffer);

        pbuffer = strtok(NULL, ":");
        persons[i].age = atoi(pbuffer);

        pbuffer = strtok(NULL, ":");
        persons[i].sex = pbuffer[0];
    }
    printf("Rendezes elott\n");
    printf_struct_array(persons, line_counter);

    qsort(persons, line_counter, sizeof(Person), compare_struct);
    printf("\nRendezes utan\n");
    printf_struct_array(persons, line_counter);

    fclose(fp);

    return EXIT_SUCCESS;
}

int compare_struct(const void *a, const void *b)
{
    Person a_person = *(Person *)a;
    Person b_person = *(Person *)b;

    if (a_person.sex - b_person.sex > 0) // először nem szerint csokkeno sorrend (nok elore)
    {
        return -1;
    }
    else if (a_person.sex - b_person.sex < 0)
    {
        return 1;
    }
    else
    {
        if (a_person.age - b_person.age > 0) // aztán kor szerint novekvo sorrend (fiatalabbak elore)
        {
            return 1;
        }
        else if (a_person.age - b_person.age < 0)
        {
            return -1;
        }
        else
        {
            return strcmp(a_person.name, b_person.name); // vegul nev szerint lexikografikusan novekvo sorrend (abc sorrend)
        }
    }
}

void printf_struct_array(Person person_array[], int number_of_people)
{
    for (int i = 0; i < number_of_people; i++)
    {
        printf("%s (%d) %c\n", person_array[i].name, person_array[i].age, person_array[i].sex);
    }
}
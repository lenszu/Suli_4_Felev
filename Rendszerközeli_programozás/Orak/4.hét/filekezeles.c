#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

double veletlen(double upper, double lower)
{
    return (double)rand() / RAND_MAX * (upper - lower) + lower;
}

int main(int argc, char *argv[], char *env[])
{
    srand(time(NULL));
    // valos szamokat akarunk file-ba 0-1millio, veletlenül, 1000-elemu float tomb, szamok.txt file-ba elmentjük
    // 821. elemet kiolvassa
    FILE *f;
    double tomb[1000];
    for (int i = 0; i < 1000; i++)
    {
        tomb[i] = veletlen(1000000, 0);
        printf("%f\n", tomb[i]);
    }

    f = fopen("szamok.txt", "w+");

    for (int i = 0; i < 100)
        fprintf(f, "%f \n", tomb[i]);
}
fclose(f);
return 0;
}

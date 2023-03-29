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
    int f,fb;
    double tomb[1000];
    for (int i = 0; i < 1000; i++)
    {
        tomb[i] = veletlen(1000000, 0);
    }

    f = open("szamok.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    for (int i = 0; i < 1000; i++)
    {
        write(f, &tomb[i], sizeof(double));
    }
    close(f);

    fb = open("konnyebb.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fb,tomb,sizeof(tomb));
    close(fb);
    return 0;
}
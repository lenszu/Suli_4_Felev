#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[], char *env[])
{
    // i want to read from a file.
    // i don't know how many lines are in the file.
    // i want to read the file line by line.
    //i want to use fgets() to read the file line by line.

      FILE *file = fopen("Measurement.txt", "r");
      char *line = NULL;
      int size=0;
      while(!feof(file)){
        size++;
      }
      printf("%d",size);
      fclose(file);
      return 0;
    
}
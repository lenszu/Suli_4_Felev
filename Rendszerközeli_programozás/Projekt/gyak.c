#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid = FindPID();
    printf("%d", pid);
    return 0;
}
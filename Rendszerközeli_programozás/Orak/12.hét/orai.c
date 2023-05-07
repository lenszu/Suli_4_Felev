#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <signal.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <omp.h>

int main(int argc, char *argv[], char *env[])
{
    int be = open("proc2.bmp", O_RDWR);
    int length = 66;
    unsigned char *buffer = malloc(length);
    read(be, buffer, length);
    // 0, 44 , 105
    for (int i = 54; i < 66; i++)
    {
        // printf("%d\n", buffer[i]);
        buffer[i] = 0b00000010;
    }
    write(be, buffer, length);
    close(be);
}
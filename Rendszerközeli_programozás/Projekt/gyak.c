#include "Functions.h"
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

int main()
{
  int *tomb = calloc(50, sizeof(int));
  for (int i = 0; i > -50; i--)
  {
    tomb[i*-1]=i;
  }
  BMPcreator(tomb, 50);
  // free(tomb);
  return 0;
}

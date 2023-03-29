#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <fcntl.h>
// fuggveny, alapertemlezett konyvtarat visszaadja a felhasznalonak
// beolvasunk stringeket, ha egyezik akkor belepunk oda,
// ha nem akkor újra kiiratjuk

FILE *browseForOpen(){
    DIR *d;
    FILE *f;
    char name[256];
    struct dirent *entry;
    struct stat inode;
    do
    {
        d=opendir(".");
        while ((entry=readdir(d))!=NULL)
        {
            printf("%s\n",(*entry).d_name);
        }
        closedir(d);
        printf("Choose");
        scanf("%s",name);
        if (stat(name,&inode)<0) continue;
        if (inode.st_mode&S_IFREG) break;
        chdir(name);
    } while (1);
    return fopen(name,"r");
}

int main(int argc, char *argv[], char *env[])
{
    FILE *f;
    char c;
    f=fopen("")
    char *tomb[20];
    int i=0;

    while (!feof(f))
    {
        fscanf(f,"%c",&c);
        printf("%c",c);
        tomb[i]=&c;
        i++;
    }
    fclose(f);
    system("touch tmp.txt");
    system("echo $HOME > tmp.txt");
    return 0;
}
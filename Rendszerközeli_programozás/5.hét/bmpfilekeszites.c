#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[], char *env[])
{
    // n*n-es 
    //elso fuggoleges tengely kozeperol
    //minden oszlopba, egy pontot -1,0,1
    // osszehasonlit az elozo oszlophoz kepest
    //ket szinu
    //minden biten egy szin
    //kellenek bitmuveletek is
    //header: 4 mezo,
    //pixel array offset, az elejehez kepest, mennyivel fog kezdodni a kep 10 bajttal
    //DIB: planes:1(reteg) bits/pixel:1
    //bal also sarokbol epiti fel a kepet
    //felfele megyunk soronkent
    //a soroknak oszhatonak kell lennie 32-vel, kulonben kitoltes lesz, ami nem befolyasol semmit
    int f;
    char *s="BM";
    int adat=2000;
    char tomb[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    f=open("kep.txt",O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
    write(f,&s[0],2);
    write(f,&adat,4);

    close(f);
    return EXIT_SUCCESS;
}
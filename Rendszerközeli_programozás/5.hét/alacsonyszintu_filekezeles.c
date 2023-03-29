#include <stdio.h>
//Ezek kellenek
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>  
//---------------------

// O_RDONLY
// O_WRONLY legyen lehetőségem irni, nem hoz létre
// O_RDWR
// O_CREAT hozz létre, ha nem létezett
// O_TRUNC töröld a tartalmát
// O_APPEND hozzáfűzés
// bitenkénti vagyolással kell több opciót is egyszerre megadni

// A TULAJDONOSNAK
// S_IRUSR olvasas
// S_IWUSR iras
// S_IXUSR futtathatosag
//CSOPORTONAK:
// S_IRGRP 
// S_IWGRP
// S_IXGRP
// bitenkénti vagyolással kell több opciót is egyszerre megadni
// 0 stdin
// 1 stdout
// 2 stderr
int main(int argc, char *argv[], char *env[])
{
    int f;
    int adat;
    f=open("abc.txt",O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
    //ha negativ erteket az vissza az open:
    if (f<0){
        write(2,"error",5); //mire,mit,mekkora amit kiirunk
        return 1;
    }
    //n=beolvasott karakterek száma
    // ha 0 az n, akkor nem változott a file, vagy elérte a file végét
    int n=read(0,&adat,sizeof(int)); //honnan,hova 
    lseek(f,4,SEEK_SET); //kurzor keresés,4--> hagyjuk ki az első 4 bájtot a fileból
    
    //a stringek stringkent kerülnek be beolvasáskor,
    //viszont az inteknek 1234-> elemenkent ascii kodót tárol el 00110001 00110010 ...
    //Tehát nem formáz
    //little endian módon tárolja el a bájtokat
    if (n==0){
        close(f);
    }

    return 0;
}
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

// 4. feladat
// 1. lépés
// Írj egy függvényt, amely a Linux fájlrendszer gyökerében lévő ”/proc” könyvtárnak az
// alkönyvtáraiban található ”status” nevű fájloknak a tartalmát vizsgálja meg. (Azok az alkönyvtárak
// tartalmaznak ilyen fájlokat, amelyek neve számjegy karakterrel kezdődik.) A fájl első sorának a
// formátuma: ”Name:\t%s\n”. Ha a tabulátor és az újsor karakter között a ”bash”
// karaktersorozatot található, akkor keressen az adott fájlban olyan sort, amely a ”Pid:\t” sztriggel
// kezdődik majd ezt egy egész szám követi. A függvény térjen vissza ezzel az egész számmal, ha pedig
// egyáltalán nem talál ilyen fájlt egyik alkönyvtárban sem, akkora -1 értékkel! (Persze a megnyitott
// fájlokat és könyvtárakat zárja be!) A függvény fejléce legyen a következő:
// int FindPID();
// 2. lépés
// Ideiglenes tesztként hívd meg a FindPID függvényt a főprogramban és ellenőrizd le manuálisan a
// megtalált érték helyességét! (A végső verziónak nem kell tartalmaznia ezt a tesztet.)
// 3. lépés
// A programban eddig definiált (és a jövőben definiálandó) alprogramokat szervezd ki egy külön saját,
// ”.h” kiterjesztésű header állományba, amit a main függvény forráskódjában inkludálsz is!

int main(int argc, char *argv[])
{
    int pid = FindPID();
    printf("PID: %d \t", pid);
    
    return 0;
}
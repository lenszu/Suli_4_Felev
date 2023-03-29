#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    szoveg = """

    "A katalán zászló, a Senyera színeit fogja viselni a következő idény során a spanyol élvonalban szereplő FC Barcelona labdarúgócsapata.

    A Marca című sportnapilap hétfői internetes kiadása szerint az együttes játékosai az idegenbeli mérkőzéseken húzzák majd magukra a sárga-piros csíkozású mezt - első ízben a klub történelme során.

    A döntés várhatóan nem marad politikai visszhang nélkül Spanyolországban, tekintettel a katalán önállósodási törekvésekre." """
    ekezetes = "áéíóöőúüűÁÉÍÓÖŐÚÜŰ"
    sima = "aeiooouuuAEIOOOUUU"
    tmp = 0
    
    for i in range(len(sima)):
        szoveg=szoveg.replace(ekezetes[i], sima[i])
    print(szoveg)


if __name__ == '__main__':
    main()

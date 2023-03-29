#! /usr/bin/env python3
import sys
import os
import math
import random
import time

# list=[7,3,0,2,5,1,6,4]
# +-----------------+
# | Q . . . . . . . |
# | . . . . . . Q . |
# | . . . . Q . . . |
# | . . . . . . . Q |
# | . Q . . . . . . |
# | . . . Q . . . . |
# | . . . . . Q . . |
# | . . Q . . . . . |
# +-----------------+


def sakktabla(s):
    # A 8 királynő probléma a következőképpen hangzik: egy sakktáblán helyezzünk el 8 királynőt úgy, hogy ne üssék egymást.
    szamok = []
    # A feladat most csak annyi lesz, hogy egy lehetséges állást jelenítsünk meg "grafikusan". A sakktáblát mátrix helyett egy tömbben (listában) reprezentáljuk, pl.: [7,3,0,2,5,1,6,4]. Ennek jelentése: az 1. oszlopban a királynő alulról a 8. sorban van, a 2. oszlopban alulról a 4. sorban, stb. (A listában a sorok indexelése 0-tól indul.) Ebből a listából a következő sakktáblát lehetne megjeleníteni:
    for i in sorted(s)[::-1]:
        szamok.append(s.index(i))
    print(szamok)
    print("+-----------------+")
    for i in range(8):
        print("|", end=" ")
        for j in range(8):
            if j == szamok[i]:
                print("Q", end=" ")
            else:
                print(".", end=" ")
        print("|")
    print("+-----------------+")


def main():
    sakktabla([7, 3, 0, 2, 5, 1, 6, 4])


if __name__ == '__main__':
    main()

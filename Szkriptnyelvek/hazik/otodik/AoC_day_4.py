#! /usr/bin/env python3
import sys
import os
import math
import random
import time

# AoC2017, Day 4, Part 1 (High-Entropy Passphrases)

# A munkahelyünkön egy új rendszert vezettek be: jelszó (password) helyett jelmondatot (passphrase) kell használni a belépéshez. Egy jelmondat kisbetűs szavakból áll, ahol a szavakat szóköz választja el.

# További biztonsági előírás, hogy egy jelmondatban nem szerepelhet ugyanaz a szó egynél többször.

# Példa:

#     az "aa bb cc dd ee" érvényes jelmondat
#     az "aa bb cc dd aa" nem érvényes, mivel az "aa" szó egynél többször is előfordul
#     az "aa bb cc dd aaa" érvényes, ui. az "aa" és "aaa" szavak nem azonosak

# A bemenet a jelmondatok teljes adatbázisa. Ezek közül hány jelmondat érvényes?

# A feladat bemenete innen tölthető le. A feladat eredeti kiírása itt olvasható el.
# A bemenetem: AoC.txt


def main():
    with open('AoC.txt') as f:
        lines = f.readlines()
    valid = 0
    for line in lines:
        words = line.split()
        if len(words) == len(set(words)):
            valid += 1
    print(valid)


if __name__ == '__main__':
    main()

#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    jo_ertekek=0
    helyesen_generalt=0
    random_szamok=[]
    tippek=[]
    with open("random.txt", "r") as be_random:
        random_szamok=[int(i.rstrip()) for i in be_random.readlines()]
    with open("tippek.txt","r") as be_tippek:
        tippek=[int(i.rstrip()) for i in be_tippek.readlines()]
        
    for i in range(len(random_szamok)):
        if random_szamok[i]>=0 and random_szamok[i]<=50:
            helyesen_generalt+=1
            if random_szamok[i]==tippek[i]:
                jo_ertekek+=1
    print("Eltalált számok: {0} az összes {1} helyesen generált számokból.".format(jo_ertekek,helyesen_generalt))
    


if __name__ == '__main__':
    main()

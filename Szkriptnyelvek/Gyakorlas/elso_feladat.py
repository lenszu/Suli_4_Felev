#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    with open("jegyek.txt","r") as be:
        l=[i.rstrip().split(" ")[3] for i in be.readlines()]
        szotar={}
        szotar={
            "Egyes" : 0,
            "Kettes" : 0,
            "Harmas" : 0,
            "Negyes" : 0,
            "Otos" : 0
        }
        osszeg=0
        for i in l:
            osszeg+=float(i)
            if float(i)<2.0:
                szotar["Egyes"]+=1
            elif float(i)>=2.0 and float(i)<2.5:
                szotar["Kettes"]+=1
            elif float(i)>=2.5 and float(i)<3.0:
                szotar["Harmas"]+=1
            elif float(i)>=3.0 and float(i)<3.5:
                szotar["Negyes"]+=1
            else:
                szotar["Otos"]+=1
        for key,value in szotar.items():
            print("{0} - {1}".format(key,value,))
        print("Kurzus átlag: {0}".format(round(osszeg/len(l),2)))
if __name__ == '__main__':
    main()
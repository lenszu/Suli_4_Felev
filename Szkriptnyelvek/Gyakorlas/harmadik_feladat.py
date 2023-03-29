#! /usr/bin/env python3
import sys
import os
import math
import random
import time

def karakter_szamlalo(s):
    l=[i for i in s]
    szotar={}
    for i in l:
        szotar[i]=0
        for j in s:
            if i==j:
                szotar[i]+=1
    return szotar

def main():
    if len(sys.argv)==1:
        print("Hiba! A programnak kötelező megadni legalább egy parancssori argumentumot!",file=sys.stderr)
    elif len(sys.argv)==2:
        eredmeny=karakter_szamlalo(sys.argv[1])
        for key,value in eredmeny.items():
            print("{0} - {1}".format(key,value))
    else:
        print("Hiba! A program csak egyetlen egy parancssori argumentumot fogad el!",file=sys.stderr)


if __name__ == '__main__':
    main()
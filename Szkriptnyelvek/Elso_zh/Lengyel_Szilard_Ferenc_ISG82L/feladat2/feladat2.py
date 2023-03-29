#! /usr/bin/env python3
import sys
import os
import math
import random
import time

def karakter_szuro(s):
    if len(s)==2:
        return s[1]
    else:
        szo=s[1]
        tmp=[s[i] for i in range(2,len(s))]
        for i in tmp:
            szo=szo.replace(i,"")
        return szo

def main():
    eredmeny=karakter_szuro(sys.argv)
    print(eredmeny)

if __name__ == '__main__':
    main()
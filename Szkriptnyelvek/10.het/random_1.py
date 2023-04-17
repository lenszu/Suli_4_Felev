#! /usr/bin/env python3
import sys
import os
import math
import time
import random

def shuffled(lista):
    random.shuffle(lista)
    return lista

def main():
    print(random.random()) # 0.0 - 1.0
    print(random.randint(1,10)) # [0, 10]
    
    szamok=[1,2,3,4,5,6,7,8,9]
    print(szamok)
    random.shuffle(szamok) #helyben
    print(szamok)
    print(random.choice(szamok))
    
    szamok1=[1,2,3,4,5,6,7,8,9]
    
    n=shuffled(szamok1)[-1]
    print(n)


if __name__ == '__main__':
    main()
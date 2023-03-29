#! /usr/bin/env python3
import sys
import os
import math
import random
import time

def test (szamok):
    szamok=sorted(szamok)
    if len(szamok)%2==0:
        a=(szamok[len(szamok)//2-1]+szamok[len(szamok)//2])/2
        return a
    else:
        a=szamok[len(szamok)//2]
        return a

def main():
        print(test([1, 2, 3, 4, 5]) == 3)
        print(test([3, 1, 2, 5, 3]) == 3)
        print(test([1, 300, 2, 200, 1]) == 2)
        print(test([3, 6, 20, 99, 10, 15]) == 12.5)


if __name__ == '__main__':
    main()
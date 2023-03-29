#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    tmp = ""
    x = int(input("Adjon meg egy PARATLAN szamot: "))
    if x % 2 != 0:
        for i in range(1, x+1, 2):
            for j in range(1, i+1):
                tmp += "*"
            print(tmp.center(x))
            tmp = ""

        for i in range(x-2, 0, -2):
            for j in range(i, 0, -1):
                tmp += "*"
            print(tmp.center(x))
            tmp = ""
    else:
        print("Ismetlem, PARATLAN szamot adjon meg!")

if __name__ == '__main__':
    main()

#! /usr/bin/env python3
import sys
import os
import math
import random
import time

def loop(szam,d=False):
    if d:
        print("#Ciklus kezdete")
        for i in range(1,6):
            print(i,end=" ")
            if i==5:
                print()
                break
        print("#Ciklus Vege")
    else:
        for i in range(1,6):
            print(i,end=" ")
            if i==5:
                print()
                break

def main():
    loop(5)
    print("_--------------------------_")
    loop(5,d=True)


if __name__ == '__main__':
    main()
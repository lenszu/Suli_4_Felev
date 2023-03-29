#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    tmp=[]
    Big_list=[]
    n=1
    with open("szamok.txt","r") as be:
        l=[i.rstrip() for i in be.read() if i.isdigit()]
        for i in range(len(l)):
            tmp=(l[i:i+5])
            for j in range(len(tmp)):
                n*=int(tmp[j])
            Big_list.append(n)
            n=1
            tmp.clear()
        print(Big_list)
        print(max(Big_list))
if __name__ == '__main__':
    main()

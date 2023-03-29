#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    if len(sys.argv)==1:
        print("Hiba! Meg kell adni legalább egy parancssori argumentumot!",file=sys.stderr)
    elif len(sys.argv)==2:
        if len(sys.argv[1])>10:
            print("Hiba! Túl hosszú parancssori argumentum!",file=sys.stderr)
        elif len(sys.argv[1])<10:
            print("Hiba! Túl rövid parancssori argumentum!",file=sys.stderr)
        else:
            l=[ord(i) for i in sys.argv[1]]
            l_paros=[int(1.5*i) for i in l if i%2==0]
            l_paratlan=[-2*i for i in l if i%2!=0]
            print(l_paros+l_paratlan)
        


if __name__ == '__main__':
    main()
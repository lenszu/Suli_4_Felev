
import sys
import os
import math
import random
import time

def SoP(tomb):
    sum=1
    if len(tomb)>1:
        for i in tomb:
            sum*=i
    return sum

def main():
    l=[4,5,6,7,8]
    result=SoP(l)
    print("A megkapott osszeg: {0}".format(result))


if __name__ == '__main__':
    main()
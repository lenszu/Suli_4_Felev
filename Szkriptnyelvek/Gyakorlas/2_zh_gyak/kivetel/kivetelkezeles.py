#! /usr/bin/env python3
import sys
import os
import math
import random
import time

def concat(l):
    try:
        for i in range(1,len(l)):
            with open(l[i],"r") as be:
                print("---",l[i])
                for line in be:
                    print(line)
    except IOError as e:
        print("Nincs ilyen file!",e)
    

def main():
    concat(sys.argv)
    


if __name__ == '__main__':
    main()
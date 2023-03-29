#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    a=list(str(pow(2,1000)))
    ossz=0
    for i in range(len(a)):    
        ossz+=int(a[i])
    print(ossz)

if __name__ == '__main__':
    main()
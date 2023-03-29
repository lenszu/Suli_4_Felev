#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    a=pow(sum(list(range(1,101))),2) #osszegek negyzete
    tmp=list(range(1,101))
    b=[pow(i,2) for i in tmp]
    b=sum(b)
    print(a-b)


if __name__ == '__main__':
    main()
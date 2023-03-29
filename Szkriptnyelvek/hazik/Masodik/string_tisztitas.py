import sys
import os
import math
import random
import time


def Cleaning(s):
    s=s.replace(" ","")
    return s

def main():
    s="192.20.246.138:\n 6666"
    result=Cleaning(s)
    print(result)


if __name__ == '__main__':
    main()
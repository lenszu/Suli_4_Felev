#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    str1 = "python"
    str2 = False
    print(bool(str1))
    print(bool(str2))
    
    if(bool(str1)!=bool(str2)):
        print("A ket elem kulonbozo, tehat 1")
    else:
        print("A ket elem megegyezik tehat 0")


if __name__ == '__main__':
    main()

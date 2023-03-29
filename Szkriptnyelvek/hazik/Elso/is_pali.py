import sys
import os
import math
import random
import time


def is_pali(szo):
    szo_reverse = szo[::-1]
    for i in range(len(szo)):
        if szo[i] != szo_reverse[i]:
            print("Ez nem palindrom!")
            return 0
    print("Ez a szo palindrom!")


def main():
    be = input("adj meg egy szot: ")
    is_pali(be)


if __name__ == '__main__':
    main()

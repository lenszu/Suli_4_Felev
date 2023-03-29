#! /usr/bin/env python3
import sys
import os
import math
import random
import time

def anagramma(s1, s2):
    return sorted(s1) == sorted(s2)


def main():
    s1=input("1. szó: ")
    s2=input("2. szó: ")
    s2=s2.lower().replace(" ", "")
    s1=s1.lower().replace(" ", "")
    if anagramma(s1, s2):
        print("Anagramma")
    else:
        print("Nem anagramma")


if __name__ == '__main__':
    main()
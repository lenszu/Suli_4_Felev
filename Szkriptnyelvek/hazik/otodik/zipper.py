#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    chars = "abcdefghijklmnopqrstuvwxyz"
    codes = list(range(ord('a'), ord('z')+1))
    zipping=list(zip(chars,codes))
                 
    for t in zipping:
        print(t)


if __name__ == '__main__':
    main()
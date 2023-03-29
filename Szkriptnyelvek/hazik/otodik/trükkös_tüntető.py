#! /usr/bin/env python3
import sys
import os
import math
import random
import time

# binary to text decoder

def main():
    tmp=[]
    with open("a.txt", "r") as f:
        lines = [ line.strip() for line in f.readlines()]
    for line in lines:
        print("".join([chr(int(x, 2)) for x in line.split(" ")]))
        tmp.append("".join([chr(int(x, 2)) for x in line.split(" ")]))
    print("".join(tmp))
        


if __name__ == '__main__':
    main()
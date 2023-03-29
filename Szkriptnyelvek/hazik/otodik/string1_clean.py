#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    with open("string1.txt","r") as be:
        l=[i.rstrip() for i in be.readlines() if not i.startswith("#")|i.startswith("    # ")]
        for i in l:
            print(i)


if __name__ == '__main__':
    main()
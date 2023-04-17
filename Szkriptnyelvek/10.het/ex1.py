#! /usr/bin/env python3
import sys
import os
import math
import random
import time
import modul


def main():
    l=[n for n in range(100) if modul.is_prime(n)]
    print(modul.hello())

if __name__ == '__main__':
    main()
import sys
import os
import math
import random
import time

# Capitalize bemutatása


def metodus(nev):
    print("Ez a metodus, bekért egy parancssori argumentumot.")
    print("hello {0}!".format(nev.capitalize()))
    print("a \"Capitalize\" metódus pedig az első betüt nagyra állítja")


def main():
    metodus(sys.argv[1])


if __name__ == '__main__':
    main()

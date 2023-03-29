#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    elso = "␗"
    masodik = "Ѡ"
    harom = int(ord("Ѓ"))-int(ord("Ѐ"))
    ketto = int(ord("Ђ"))-int(ord("Ѐ"))
    egy = (int(ord("Ђ"))-int(ord("Ё")))
    datum = str(ord(masodik))[ketto:]+str(ord(elso))[egy:harom]

    print("{0}".format(datum))


if __name__ == '__main__':
    main()

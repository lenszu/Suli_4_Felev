#! /usr/bin/env python3
import sys
import os
import math
import random
import time

def hang(szo):
    MELY_MGHK = "aáoóuú"
    MAGAS_MGHK = "eéiíöőüű"
    mely=False
    magas=False
    for i in range(len(szo)):
        if MELY_MGHK.find(szo[i])>=0:
            mely=True
        if MAGAS_MGHK.find(szo[i])>=0:
            magas=True
    if mely and magas:
        return "Vegyes"
    elif mely and not magas:
        return "Mély hang"
    elif not mely and magas:
        return "Magas hang"
    else:
        return "Egyik sem"


def main():
    words = ["ablak", "erkély", "kisvasút", "magas", "mély"]
    for i in words:
        print(hang(i))

if __name__ == '__main__':
    main()

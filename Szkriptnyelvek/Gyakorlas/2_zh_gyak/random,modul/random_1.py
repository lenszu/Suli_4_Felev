#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def shuffled(lista):
    random.shuffle(lista)
    return lista


def main():
    # valós szám [0.0-1.0[ között balról zárt, így a 0-át felveheti, jobbról nyílt, így az 1-et már nem veheti fel
    print(random.random())
    l = [random.randint(1, 10) for i in range(10)]
    print(l, f"fixalt lista")
    random.shuffle(l)
    print(l, f"shuffled lista")
    print("-"*20)
    n=shuffled(l)[-1]
    print(f"{n}")


if __name__ == '__main__':
    main()

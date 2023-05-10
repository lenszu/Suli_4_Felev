#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    while (True):
        try:
            szam1 = float(input("adja meg egy elsot: "))
            szam2 = float(input("adja meg a masodikat: "))
            osztas = szam1/szam2
            print("az osztas eredmenye: {0:.2f}".format(osztas))
            print("-"*10)
        except ZeroDivisionError as e:
            print("Nullával nem osztunk te!", e)
            print("-"*10)
        except EOFError as e:
            break
        except ValueError as e:
            print("Számot te fiju..", e)
            print("-"*10)


if __name__ == '__main__':
    main()

#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def printing(s):
    result = []
    tmp = s.split(",")
    for i in tmp:
        if i.find('-') > 0:
            tmp_s = i.split("-")
            for j in range(int(tmp_s[0]), int(tmp_s[1])+1):
                result.append(j)
        else:
            result.append(int(i))
    result.sort()
    return result


def main():
    x = input("Adja meg a nyomtatni kívánt oldalakat: ")
    lista = printing(x)
    print(lista)


if __name__ == '__main__':
    main()

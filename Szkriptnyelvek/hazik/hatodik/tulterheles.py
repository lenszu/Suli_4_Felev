#! /usr/bin/env python3
import sys
import os
import math
import random
import time

class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __str__(self):
        return "({0},{1})".format(self.x, self.y)

    def __add__(self, other):
        x = self.x + other.x
        y = self.y + other.y
        return Point(x, y)

def main():
    a=Point(1,2)
    b=Point(3,4)
    print(a+b)


if __name__ == '__main__':
    main()
#!/usr/bin/env python3

import math


def distance(p1, p2):
    x, y = p1
    a, b = p2
    return math.sqrt(math.pow(a-x, 2)+math.pow(b-y, 2))


def main():
    p1 = (1, 2)
    p2 = (6, 5)
    print('A ket pont kozti tavolsag:', distance(p1, p2))

#############################################################################


if __name__ == "__main__":
    main()

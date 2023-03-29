#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    sumo = 0
    for i in range(1, 101):
        for j in range(len(str(i))):
            sumo += int(str(i)[j])
    print(sumo)


if __name__ == '__main__':
    main()

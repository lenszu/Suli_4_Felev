#! /usr/bin/env python3
import sys
import os
import math
import random
import time
from ex1 import is_prime


def main():
    for i in range(1,101):
        print(f"{i} ",is_prime(i))
        


if __name__ == '__main__':
    main()
import sys
import os
import math
import random
import time
import urllib.request


def main():
    kep="https://www.pet4you.hu/img/big/15006357333312_1.jpg?1541453100"
    nev="cica.jpg"
    urllib.request.urlretrieve(kep,nev)


if __name__ == '__main__':
    main()
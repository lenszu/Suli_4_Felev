import sys
import os
import math
import random
import time


def main():
    url="https://www.pet4you.hu/img/big/15006357333312_1.jpg?1541453100"
    nev="cica.jpg"
    
    utasitas=f"curl {url} --output {nev}"
    os.system(utasitas)


if __name__ == '__main__':
    main()
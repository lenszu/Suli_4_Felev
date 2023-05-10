#! /usr/bin/env python3
import sys
import os
import math
import random
import time
import urllib.request
from modul_getPage import getPage


def main():
    # asd=urllib.request.urlopen("https://www.python.org/")
    # be=asd.read()
    # print(type(be))
    # html=be.decode("utf-8")
    # print(type(html))
    # print(html)
    
    print(getPage("http://gepeszeti.hu/"))


if __name__ == '__main__':
    main()
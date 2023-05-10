#! /usr/bin/env python3
import sys
import os
import math
import random
import time
import urllib.request
import requests


def main():
    urlke = "http://gepeszeti.hu/"
    # name = "macsek.jpg"
    # urlke="https://www.youtube.com/watch?v=tPQcC9SXcLE"
    # urllib.request.urlretrieve(urlke,"cica.jpg")

    # tmp=urllib.request.urlopen(urlke)
    # tmp=tmp.read()
    # tmp=tmp.decode("utf-8")
    # print(tmp)

    # cmd = f'wget {urlke} -O {name}'
    # print(cmd)
    # os.system(cmd)
    
    r=requests.get(urlke)
    print(r.text)


if __name__ == '__main__':
    main()

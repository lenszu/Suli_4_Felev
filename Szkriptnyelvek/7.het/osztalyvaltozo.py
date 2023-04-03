#! /usr/bin/env python3
import sys
import os
import math
import random
import time

class fasz():
    szamolo=0
    def __init__(self):
        fasz.szamolo+=1 ##fontos ez a sor, mivel a fasz.VÁLTOZÓ_NÉV-nek az értékét kell átállítani
        
    def hello(self):
        print("Hello world")

def main():
    peldany=fasz()
    asd=fasz()
    
    print(fasz.szamolo)


if __name__ == '__main__':
    main()
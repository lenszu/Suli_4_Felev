#! /usr/bin/env python3
import sys
import os
import math
import random
import time
from os.path import join

class MyClass:
    def __init__(self):
        self.osztaly_lista=[]
    
    def add_in_range(self,szam,Hanyszor=1):
        for i in range(Hanyszor):
            self.osztaly_lista.append(szam)
    def Give_Back(self):
        return self.osztaly_lista


def main():
    szia=MyClass()
    szia.add_in_range(2)
    print(szia.Give_Back())


if __name__ == '__main__':
    main()
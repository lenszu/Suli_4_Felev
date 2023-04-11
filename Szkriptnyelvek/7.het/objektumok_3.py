#! /usr/bin/env python3
import sys
import os
import math
import random
import time

# konténer osztály


class Bag:
    def __init__(self): ##konstruktor
        self.adatok = []

    def add(self,i):
        self.adatok.append(i)
    
    # def ki(self):
    #     print(self.adatok)

    def __str__(self): ##to_string metódus
        tmp="( "
        for i in 
    
    def add_twice(self,i):
        for b in range(2):
            self.add(i)
def main():
    b=Bag()
    b.add(5)
    b.add(10)
    b.add_twice(20)
    b.adatok.clear() ## a mainben is lehet a példányváltozókat módosítani
    print(b)
    
if __name__ == '__main__':
    main()

#! /usr/bin/env python3
import sys
import os
import math
import random
import time
 # funkciók: üres-e, tele-e, Sorból, Sorba, üres

class Sor:
    def __init__(self):
        self.Sor=[]
    
    def betesz(self,i):
        self.Sor.append(i)
        
    def ures(self):
        if len(self.Sor)==0:
            return True
        else:
            return False
        
    def kivesz(self):
        if self.ures():
            return None
        else:
            return self.Sor.pop()
        
    def meret(self):
        return len(self.Sor)
    
    def __str__(self) -> str:
        return "{0}".format(self.Sor)

class Verem():
    def __init__(self):
        self.verem=[]
    
    def betesz(self,i):
        self.verem.append(i)
        
    def ures(self):
        if len(self.verem)==0:
            return True
        else:
            return False
    def meret(self):
        return len(self.verem)
    
    def kivesz(self):
        if self.ures():
            return None
        else:
            return self.verem.pop() 
    
    def __str__(self) -> str:
        tmp="( "
        for i in self.verem:
            tmp+=str(i)+" "
        return tmp
        
def main():
    v = Sor()      # üres verem létrehozása
    print(v)         # [
    print(v.ures())  # True
    v.betesz(1)
    v.betesz(4)
    v.betesz(5)
    print(v)         # [1 4 5   
    print(v.meret()) # 3
    print(v.ures())  # False
    x = v.kivesz()
    print(x)         # 5
    print(v)         # [1 4
    v.kivesz()
    v.kivesz()       # most már üres
    x = v.kivesz()
    print(x)         # None (jelezzük pl. így, hogy egy üres veremből akarunk kivenni)


if __name__ == '__main__':
    main()
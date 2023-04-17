#! /usr/bin/env python3
import sys
import os
import math
import random
import time


# Sor adatszerkezet két veremmel

# Írjunk egy MyQueue nevű osztályt, amely egy sor adatszerkezetet implementál két verem felhasználásával.

# Vagyis az osztályon belül legyen két verem, de maga az osztály kívülről úgy működjön, mint egy sor. Valójában az osztálynak egy sor adatszerkezetet kell megvalósítania, de mi az implementáció során ezt 2 db veremmel akarjuk megoldani. (Papíron gondolják át, hogy ez hogyan lehetséges).

# Az osztály támogassa a köv. műveleteket:

#     append: beszúrás a sor végére
#     popleft: térjen vissza a sor első elemével (s ezt az elemet vegye is ki a sorból)
#     is_empty: üres-e a sor
#     size: a sorban lévő elemek száma 

# A két verem esetén csakis a szabályos veremműveletek használhatók! Vagyis új elem berakása a verem tetejére, ill. a legfelül lévő elem eltávolítása. Akár az órán vett Verem implementációt is lehet használni! 

#123
#321

class Row_2_Stack():
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    
    def add(self,number):
        self.stack1.append(number)
    
    def popleft(self):
        # for i in range(len(self.stack1),0,-1):
            # self.stack2.append(i)
        self.stack2=self.stack1[::-1]
        tmp=self.stack2.pop(len(self.stack2)-1)
        self.stack1.clear()
        self.stack1=self.stack2[::-1]
        return tmp
    
    def is_empty(self):
        if len(self.stack1)==0:
            return True
        else:
            return False
    
    def size(self):
        return len(self.stack1)
    
    def __str__(self):
        return "{0}".format(self.stack1)

def main():
    a=Row_2_Stack()
    a.add(1)
    a.add(2)
    a.add(3)
    b=a.popleft()
    c=a.popleft()
    print(b,c,a)
    print(a.is_empty())
    print(a.size())
    d=a.popleft()
    print(a.is_empty())
    print(a.size())


if __name__ == '__main__':
    main()
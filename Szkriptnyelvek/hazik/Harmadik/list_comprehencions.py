#! /usr/bin/env python3
import sys
import os
import math
import random
import time

# folytatás a 4-es feladattol

def main():
    # 4.
    # [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] → [2, 4, 6, 8, 10, 12, 14, 16, 18, 20] 
    a=[n*2 for n in range(1,11)]
    print("4-es feladat: {0}".format(a))
    
    # 5.
    # ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10'] → [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] (az első listában sztringek vannak) 
    btmp=['1', '2', '3', '4', '5', '6', '7', '8', '9', '10']
    b=[int(btmp[n]) for n in range(len(btmp))]
    print("5-ös feladat: {0}".format(b))
    
    # 6.
    # "1234567" → [1, 2, 3, 4, 5, 6, 7], vagyis van számunk sztring formátumban, s egy listába be akarjuk tenni a számjegyeit (számokként) 
    ctmp="1234567"
    c=[int(ctmp[n]) for n in range(len(ctmp))]
    print("6-os feladat: {0}".format(c))
    
    # 7.
    # 'The quick brown fox jumps over the lazy dog' → [3, 5, 5, 3, 5, 4, 3, 4, 3], vagyis állapítsuk meg az egyes szavak hosszát 
    dtmp='The quick brown fox jumps over the lazy dog'.split(' ')
    d=[len(n) for n in dtmp]
    print("7-es feladat: {0}".format(d))
    
    # 8.
    # "python is an awesome language" → ['p', 'i', 'a', 'a', 'l'], vagyis egy sztring szavainak a kezdőbetűit gyűjtsük össze egy listában 
    etmp="python is an awesome language".split(' ')
    e=[n[0] for n in etmp]
    print("8-as feladat: {0}".format(e))
    
    # 9. feladat
    # 'The quick brown fox jumps over the lazy dog' → [('The', 3), ('quick', 5), ('brown', 5), ('fox', 3), ('jumps', 5), ('over', 4), ('the', 3), ('lazy', 4), ('dog', 3)], vagyis a listában tuple-öket helyezzünk el a következő szerkezettel: (szó, szóhossz). 
    ftmp='The quick brown fox jumps over the lazy dog'.split(' ')
    f=tuple()

if __name__ == '__main__':
    main()
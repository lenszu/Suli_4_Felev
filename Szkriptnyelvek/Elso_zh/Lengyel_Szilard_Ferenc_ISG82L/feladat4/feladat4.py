#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    max_lista=[]
    i=2
    lista=[]
    x=""
    x=input("Kérem adja meg az 1. szót: ")
    while (x!='*'):
        lista.append(x)
        x=input("Kérem adja meg az {0}. szót: ".format(i))
        i+=1
    if len(lista)>=3:
        lista=sorted(lista,key=len)[::-1]
        # print(lista)
        for i in range(len(lista)):
            if i==3:
                break
            max_lista.append(lista[i])
        print("Leghosszabb sztringek:")
        for i in range(len(max_lista)):
            print("  {0}. {1}".format(i+1,max_lista[i]))
    else:
        print("Hiba! Túl kevés sztring, minimum 3 darab kell!",file=sys.stderr)
        
        
            
    
        


if __name__ == '__main__':
    main()

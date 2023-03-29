#! /usr/bin/env python3
import sys
import os
import math
import random
import time

magas="ei"
mely="auo"

l_mely=[]
l_magas=[]
l_vegyes=[]
l_nincs=[]

def main():
    tmp_1=0
    tmp_2=0
    me=0
    ma=0
    vegyes=0
    with open("words.txt","r") as be:
        l=[i.rstrip() for i in be.readlines() if i.rstrip().isalpha()]
        print(len(l))
        for i in l:
            for j in i:
                if magas.find(j)>0:
                    tmp_1+=1
                elif mely.find(j)>0:
                    tmp_2+=1
                    
            if tmp_1&tmp_2:
                l_vegyes.append(i)
                vegyes+=1
            elif tmp_1:
                l_magas.append(i)
                ma+=1
            elif tmp_2:
                l_mely.append(i)
                me+=1
            else:
                l_nincs.append(i)
            tmp_1=0
            tmp_2=0
        print("Magas: {0}\nMely: {1}\nVegyes: {2}\n".format(ma,me,vegyes))
        print(len(l_magas),len(l_mely),len(l_vegyes),len(l_nincs))
    with open("ki.txt","w") as ki:
        for i in l:
            print(i,file=ki)

if __name__ == '__main__':
    main()
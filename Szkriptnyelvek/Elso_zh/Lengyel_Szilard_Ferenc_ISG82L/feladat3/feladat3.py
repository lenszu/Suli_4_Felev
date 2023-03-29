#! /usr/bin/env python3
import sys
import os
import math
import random
import time


def main():
    szotar={}
    with open("hibas_bevasarlo_lista.txt","r")as be:
        halmaz=set([i.split(" - ")[0] for i in be.readlines()])
        be.seek(0)
        l=[i.rstrip() for i in be.readlines()]
        
        for i in halmaz:
            szotar[i]=0
            for j in l:
                if i==j.split(" - ")[0]:
                    szotar[i]+=int(j.split(" - ")[1])
                    
    with open("bevasarlo_lista.txt","w") as ki:
                for k,j in szotar.items():
                    print("{0} - {1}".format(k,j),file=ki)


if __name__ == '__main__':
    main()
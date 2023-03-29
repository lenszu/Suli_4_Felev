#! /usr/bin/env python3
import sys
import os
import math
import random
import time

def valid(text, chars="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"):
    s=list(n for n in text if chars.find(n)>=0)
    a=""
    for i in s:
        a+=i
    return a

def main():
    a=valid("Barking!")                             
    b=valid("KL754", "0123456789")                  
    c=valid("BEAN", "abcdefghijklmnopqrstuvwxyz")  
    
    print(a)
    print(b)
    print(c)

if __name__ == '__main__':
    main()
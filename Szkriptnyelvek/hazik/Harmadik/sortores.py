#! /usr/bin/env python3
import sys
import random as r

UPTO = 100


def main():
    a=0
    for i in range(UPTO):
        a+=1
        print(r.randint(0, 9), end="")
        if a%10==0:
            print()
    
if __name__ == '__main__':
    main()
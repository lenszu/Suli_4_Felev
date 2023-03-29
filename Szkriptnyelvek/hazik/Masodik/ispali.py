import sys
import os
import math
import random
import time

def IsPaliRek(s):
    
            if len(s) <= 1:
                return True
            else:
                if s[0] == s[-1]:
                    if len(s) == 2:
                        return True
                    else:
                        a=s[1:-1]
                        IsPaliRek(a)     
                else:                
                    return False
                
        

def IsPali(s):
    i=0
    neg=len(s)-1
    while(i<=len(s)/2):
        if(s[i] != s[neg]):
            return False
        neg-=1
        i+=1
    return True        

def main():
    s=input("Adj meg egy szot, es eldontom hogy palindrom-e: ")
    result_1=IsPali(s)
    result_2=IsPaliRek(s)
    print()
    print("Példányosítás nélkül és Rekurzivan: ")
    if(result_1):
        print("Ez a szo palindrom")
    else:
        print("Ez a szo NEM palindrom")    


if __name__ == '__main__':
    main()
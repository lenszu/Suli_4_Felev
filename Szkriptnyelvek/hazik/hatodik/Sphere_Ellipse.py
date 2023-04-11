#! /usr/bin/env python3
import sys
import os
import math
import random
import time

class Sphere():
    def __init__(self,r):
        self.sugár=r
        self.térfogat=0
        self.felszín=0
    
    def Felszín(self):
        return 4*pow(self.sugár,2)*math.pi
    
    def Térfogat(self):
        return (4/3)*pow(self.sugár,4)*math.pi

class Ellipse():
    # A, B, and C is just (4/3) * Pi * A * B * C
    def __init__(self,a,b,c):
        self.A=a
        self.B=b
        self.C=c
    def Kerület(self):
        return (4/3)*math.pi*self.A*self.B*self.C
    
    def Terület(self):
        return math.pi*self.A*self.B
    # Ellipse (ellipszis) osztályok megírása; a Sphere osztály esetén terheljük túl a következő operátorokat: <, <=, >, >= .
    
    def __lt__(self, other):
        return self.Terület() < other.Terület()
    def __gt__(self, other):
        return self.Terület() > other.Terület()
    def __ge__(self, other):
        return self.Terület() >= other.Terület()
    def __le__(self,other):
        return self.Terület() <= other.Terület()
    
def main():
    a=Sphere(2)
    print("Gömb: ")
    print("-"*20)
    felszin=a.Felszín()
    print(str(felszin)+" cm^2")
    térfogat=a.Térfogat()
    print(str(térfogat)+" cm^2")
    
    b=Ellipse(2,3,3)
    print("-"*20)
    print("Ellipszis: ")
    print("-"*20)
    kerület=b.Kerület()
    print(str(kerület)+" cm^2")
    terület=b.Terület()
    print(str(terület)+" cm^2")
    c=Ellipse(4,4,4)
    print(b>c)

if __name__ == '__main__':
    main()
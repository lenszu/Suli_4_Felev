#! /usr/bin/env python3
import sys
import os
import math
import random
import time

class Hello:
    # "self" a legelső paramétere
    def create_name(self,s):
       self.fasz=s ##futásidejű példányváltozó készítése
       
    def display_name(self):
        return self.fasz
    def greet(self):
        print("hello ",self.fasz)
    
class EmptyClass:
    pass

class MyClass:
    def hello(self): 
        return "Hello World!"

def main():
    obj=MyClass()
    print(obj.hello())
    
    h=Hello()
    h.create_name("Alice")
    print(h.display_name())
    h.greet()

if __name__ == '__main__':
    main()
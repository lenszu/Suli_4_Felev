#! /usr/bin/env python3
import sys
import os
import math
import random
import time


class Greefing:
    def __init__(self,name): ##példányosításkor megadott paraméter elmentése 
        self.Név=name
        
    def say_hi(self):
        print(self.Név)

def main():
    g=Greefing("Alice") ##konstruktorba írás
    g.say_hi()


if __name__ == '__main__':
    main()
#! /usr/bin/env python3
import sys
import os
import math
import random
import time
import re

def main():
    with open("s.txt","r") as be:
        l=[i.strip().split("\t") for i in be.readlines()]
        # for i in l:
        #     print(i)
        sum=0

        for index in range(len(l)):
            for belso_index in range(len(l[index])):
                l[index][belso_index]=int(l[index][belso_index])
            sum+=max(l[index])-min(l[index])
        print(sum)
if __name__ == '__main__':
    main()
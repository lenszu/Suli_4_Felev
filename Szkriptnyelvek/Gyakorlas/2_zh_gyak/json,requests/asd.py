#!/usr/bin/env python3
import sys
import os
import math
import random
import time
import json

from pprint import pprint

def main():
    fname="person.json"
    f=open(fname)
    d=json.load(f)
    f.close()
    
    make_set=set()
    print(type(make_set))
    tmp_dict={}
    
    print(type(d))
    # make a for loop to print the name and age of each person using "items method"
    for i,j in d.items():
        if i=="salary":
            j=12
        tmp_dict[i]=j
    # print(tmp_dict)
    
    pprint(d)


if __name__ == '__main__':
    main()

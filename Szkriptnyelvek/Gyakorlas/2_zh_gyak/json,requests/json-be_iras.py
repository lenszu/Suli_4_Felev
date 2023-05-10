#! /usr/bin/env python3
import sys
import os
import math
import random
import time
import json

def bele():
    tmp = {
        "last": "Doe",
        "first": "John",
        "age": 39,
        "sex": "M",
        "registered": True,
        "salary": 80000
        }
    
    f=open("employee.json","w")
    json.dump(tmp,f,indent=4,sort_keys=True)
    f.close()


if __name__ == '__main__':
    bele()

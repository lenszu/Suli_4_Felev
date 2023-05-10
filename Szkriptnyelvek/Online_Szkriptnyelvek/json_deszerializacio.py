import sys
import os
import math
import random
import time
import json
from pprint import pprint

def main():
    son={
    "last": "Doe",
    "first": "John",
    "age": 39,
    "sex": "M",
    "registered": True,
    "salary": 70000
}
    file=open("adatok.json","w")
    json.dump(son,file,indent=4)
    file.close()
    print(json.dumps(son))



if __name__ == '__main__':
    main()
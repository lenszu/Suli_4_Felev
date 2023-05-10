import sys
import os
import math
import random
import time
#ez kell hozzá
import json
from pprint import pprint

def main():
    file=open("person.json","r")
    jsonf_file=json.load(file)
    file.close()
    
    print(jsonf_file)
    
    pprint(jsonf_file,indent=4)


if __name__ == '__main__':
    main()
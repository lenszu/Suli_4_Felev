#! /usr/bin/env python3
import sys
import os
import math
import random
import time

s="""
#! /usr/bin/env python3
import sys


def main():
    tmp = ""
    for i in range(97, 123):
        tmp += chr(i)
    if sys.argv[0].split("/")[len(sys.argv[0].split("/"))-1]=="a-z.py":
        print(tmp)
    elif sys.argv[0].split("/")[len(sys.argv[0].split("/"))-1]=="z-a.py":
        print(tmp[::-1])


if __name__ == '__main__':
    main()

"""

#97-122

def main():
    with open("a-z.py","w") as a_z:
        print(s,file=a_z)
        src="a-z.py"
        dst="z-a.py"
        os.symlink(src,dst)
        

if __name__ == '__main__':
    main()
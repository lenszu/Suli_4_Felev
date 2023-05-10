
import sys
import os
import math
import random
import time
import requests

def main():
    url="https://index.hu"
    r=requests.get(url)
    print(r.url)


if __name__ == '__main__':
    main()
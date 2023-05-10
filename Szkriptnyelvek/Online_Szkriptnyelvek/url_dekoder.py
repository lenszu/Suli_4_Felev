import sys
import os
import math
import random
import time
# html forraskod lehuzo
import urllib.request


def main():
    valasz = urllib.request.urlopen("https://www.python.org/")
    print(type(valasz))
    forras = valasz.read()
    # print(forras)
    # print(type(forras))
    html_forraskod=forras.decode("utf-8")
    print(html_forraskod)
    print(type(html_forraskod))


if __name__ == '__main__':
    main()

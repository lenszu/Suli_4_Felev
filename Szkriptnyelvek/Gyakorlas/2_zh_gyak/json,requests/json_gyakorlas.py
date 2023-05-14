#! /usr/bin/env python3
import sys
import os
import math
import random
import time
import json
from pprint import pprint
import urllib.request


class Players():

    Jatekosok = []

    def __init__(self, nev, osztaly, szint):
        self.nev = nev
        self.osztaly = osztaly
        self.szint = szint
        Players.Jatekosok.append(self)

    def __str__(self):
        return f"{self.nev}, {self.osztaly}, {self.szint}"

    @staticmethod
    def find_strongest_hero(lista):
        result = []
        tmp_dict={}
        max=lista[0]["level"]
        for i in lista:
            if i["level"]>max:
                max=i["level"]
                result.clear()
                result.append(i)
        for i,j in result[0].items():
            tmp_dict[i]=j
        return tmp_dict
        


def main():
    # url_ke = "https://raw.githubusercontent.com/suvicsabika/szkriptnyelvek_2023_tavasz_02/main/masodik_zh_forras_fajlok/players.json"

    # command = f"wget {url_ke} "
    # print(command)
    # os.system(command)

    tmp_list = []

    f = open("players.json", "r")
    formatted_f = json.load(f)
    for i in formatted_f:
        tmp_list.append(i)
    # print(tmp_list)
    result=Players.find_strongest_hero(tmp_list)
    print(result)
    f.close()
    
    o=open("strongest.json","w")
    json.dump(result,o,indent=4)
    o.close()
    # 1. lépés: Letöltjük a json netröl, a curl -o {url}-el
    # 2. lépés: beolvassuk a fájlt, majd készítünk egy osztályt, melynek a konstruktora feldolgozza az elemeket
    # 3. lépés: átírjuk a kiiratást, hogy kitudjuk iratni
    # 4. lépés: írunk példánymetódusokat, osztálymetódusokat(@staticmethod)


if __name__ == '__main__':
    main()

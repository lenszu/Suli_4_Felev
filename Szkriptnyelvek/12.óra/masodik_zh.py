#!/usr/bin/env python3
import sys
import random
from pprint import pprint

class Hallgato():

    hallgatok = []

    def __init__(self, nev, eletkor, szak):
        self.nev = nev
        self.eletkor = eletkor
        self.szak = szak.upper()

    @staticmethod  # osztálymetódus
    def szak_hallgato(szak):

        szak_hallgato = []
        for akt_hallgato in Hallgato.hallgatok:
            if akt_hallgato.szak == szak.upper():
                szak_hallgato.append(akt_hallgato)

        if len(szak_hallgato) == 0:
            return []

        return szak_hallgato

    def random_kodnev(self):
        pupi = ''.join(random.sample(self.nev, len(self.nev)))
        return pupi

    def __lt__(a, b):
        return a.eletkor < b.eletkor

    def __gt__(a, b):
        return a.eletkor > b.eletkor

    def __str__(self):
        return f"{self.nev}, {self.eletkor} ,{self.szak}"


def main():
    with open("nevek.csv", "r") as be:
        l = [s.rstrip().split(",") for s in be.readlines()]
        # aktualis_hallgato=Hallgato()
        for i in l:
            aktualis_hallgato = Hallgato(i[0], i[1], i[2])
            # hozzaadjuk az osztaly listahoz az aktualis peldanyt
            Hallgato.hallgatok.append(aktualis_hallgato)
            # print(aktualis_hallgato)
            # print(aktualis_hallgato.random_kodnev())
        # for i in l:
        #     print(i)
        
    min=aktualis_hallgato.hallgatok[0].eletkor
    max=aktualis_hallgato.hallgatok[0].eletkor
    for j in aktualis_hallgato.hallgatok:
        if j.eletkor>max:
            max=j.eletkor
            l_max=j
        if j.eletkor<min:
            min=j.eletkor
            l_min=j
    # print(l_min,"|",l_max)
    
    l = aktualis_hallgato.szak_hallgato("PTI")
    for i in l:
        print(i)

        
        


if __name__ == "__main__":
    main()

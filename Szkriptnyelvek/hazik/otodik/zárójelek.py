#! /usr/bin/env python3
import sys
import os
import math
import random
import time

# Legyen adott egy kifejezés, melyben számok, zárójelek, illetve operátorok szerepelnek. Minket most csak a zárójelek érdekelnek. Háromféle zárójel szerepelhet a kifejezésben: "{}", "()", "[]". Ha egy zárójelet megnyitunk, akkor a típusának megfelelő párral be is kell zárni. A zárójelek hatásköre nem keresztezheti egymást. A feladat: egy kifejezésről döntsük el a zárójelek alapján, hogy helyes-e vagy sem (a számokkal és az operátorokkal most ne foglalkozzunk).
Nyito_lista = ["[","{","("]
Zaro_lista = ["]","}",")"]

def test(s):
    verem = []
    for i in s:
        if i in Nyito_lista:
            verem.append(i)
        elif i in Zaro_lista:
            pos = Zaro_lista.index(i)
            if ((len(verem) > 0) and (Nyito_lista[pos] == verem[len(verem)-1])):
                verem.pop()
            else:
                False
    if len(verem) == 0:
        return True
    else:
        return False


def main():
    print(test("((5+3)*2+1)"))
    print(test("{[(3+1)+2]+}"))
    print(test("(3+{1-1)}"))
    print(test("[1+1]+(2*2)-{3/3}"))
    print(test("(({[(((1)-2)+3)-3]/3}-3)"))


if __name__ == '__main__':
    main()

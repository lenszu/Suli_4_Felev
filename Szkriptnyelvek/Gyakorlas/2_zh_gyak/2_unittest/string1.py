#!/usr/bin/env python3
# coding: utf-8

# Copyright 2010 Google Inc.
# Licensed under the Apache License, Version 2.0
# http://www.apache.org/licenses/LICENSE-2.0

# Google's Python Class
# http://code.google.com/edu/languages/google-python-class/

# A magyar változatot készítette:
# Szathmáry László (jabba.laci@gmail.com)
# frissítés Python 3-ra: 2016.09.09.

# Alapvető sztring műveletek
# Írjuk meg az alábbi függvények törzsét. A main() fv.
# már készen van s ezeket a fv.-eket hívja meg különböző
# paraméterekkel. Ha egy fv.-t helyesen írtunk meg, akkor
# az 'OK' üzenet jelenik meg.
# A fv.-eknek vmilyen értéket kell visszaadniuk, ezt a 'return'
# után adjuk meg.


# A. donuts
# Bemenet: egy egész szám (a fánkok száma).
# Adjunk vissza egy sztringet a köv. formában: 'Fánkok száma: <count>',
# ahol <count> a bemenetként kapott érték.
# Viszont ha a fánkok száma 10 vagy több, akkor a tényleges szám helyett
# a 'sok' szót használjuk.
# Vagyis donuts(5) visszatérési értéke 'Fánkok száma: 5', míg
# donuts(23) visszatérési értéke 'Fánkok száma: sok'
def donuts(count):
    return f"Fánkok száma: {count}" if count < 10 else f"Fánkok száma: sok"


# B. both_ends
# Egy adott s sztring esetén adjunk vissza egy olyan sztringet,
# mely az eredeti sztring első 2 és utolsó 2 karakteréből áll.
# Vagyis 'spring' esetén a visszatérési érték 'spng'.
# Ha az input sztring hossza 2-nél rövidebb, akkor egy üres
# sztringet adjunk vissza.
def both_ends(s):
    return s[:2]+""+s[-2:] if len(s) > 2 else ""


# C. fix_start
# Egy adott s sztring esetén adjunk vissza egy olyan sztringet,
# melyben az első karakter összes előfordulása helyén egy '*'
# szerepel, kivéve a legelső pozíciót.
# Példa: 'babble' => 'ba**le'
# Feltételezhetjük, hogy a bemeneti sztring hossza legalább 1.
# Tipp: s.replace(stra, strb) egy olyan sztringet ad vissza,
# melyben az stra összes előfordulása ki van cserélve strb-re.
def fix_start(s):
    return s[0]+s[1:].replace(s[0], "*")


# D. mix_up
# Adott két bemeneti sztring, a és b. Adjunk vissza egyetlen sztringet,
# melyben a és b konkatenálva van úgy, hogy köztük egyetlen szóköz szerepel.
# Ezen túl cseréljük fel a két sztring első két karakterét az eredményben.
# Példa:
#   'mix', 'pod' -> 'pox mid'
#   'dog', 'dinner' -> 'dig donner'
# Feltételezhetjük, hogy a bemeneti sztringek hossza legalább 2.
def mix_up(a, b):
    return b[:2]+a[2:]+" "+a[:2]+b[2:]


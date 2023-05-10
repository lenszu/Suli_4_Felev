import sys
# itt vannak a regexekhez tartozo könyvtár
import re

def find(keresett,sztring):
    m=re.search(keresett,sztring)
    if m:
        print(m.group())
    else:
        print("Nincs benne!")
    


def main():
    print("-"*20)
    s = "reguláris kifejezések"
    keresett = "reg"
    m = re.search(keresett, s)

    print(re.search(keresett, s))  # logikai igaz/hamis
    print(m.group(), type(m.span()), m.span()[0], m.span()[1])
    m2 = re.search("cica", s)
    print("-"*20)
    if m2:
        print(m2.group())
    print(m2)
    print("-"*20)
    find(keresett,s)
    print("-"*20)
    find(r"([\w.])+@([\w.]+)","vmi jabba.laci@gmail.com vmi")


if __name__ == "__main__":
    main()

    # oop, peldany metodus, osztaly metodus, osztaly valtozo, __str__ __init__, operatorok tulterhelese
    # sajat modul unit tesztekkel, kivetel kezeles, json serializacio, töltsünk le egy adott weboldalt,

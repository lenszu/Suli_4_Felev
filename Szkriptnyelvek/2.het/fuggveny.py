import sys

def hello(name, color, what):
    #1
    print("A neve: {0}\nA szine: {1}\nA miafasz: {2}".format(name,color,what)) #.format-al adom meg a kiirando valtozokat sorrend szerint
    #2
    print("A neve: {}\nA szine: {}\nA miafasz: {}".format(name,color,what))
    #3
    print("A neve: {nev}\nA szine: {szin}\nA miafasz: {w}".format(nev=name,szin=color,w=what))
    #4
    print(f"{name.capitalize()} {color} az {what}")
    print(name.capitalize())
    
def main():
    hello("Szili","Fekete","penis")


if __name__=="__main__":
    main()
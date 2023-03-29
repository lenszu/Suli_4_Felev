import sys

G=3.14

def fasz():
    global G
    G=12
    print(G)
    

def main():
    print(G)
    fasz()


if __name__=="__main__":
    main()
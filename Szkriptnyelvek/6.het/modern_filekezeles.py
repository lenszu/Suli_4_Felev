import sys
def main():
    with open("text.txt","r") as f:
        a=f.read().splitlines()
        print(a)


if __name__=="__main__":
    main()
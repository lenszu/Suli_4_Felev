import sys

def hello(name):
    if name=="Batman" or "Robin":
        return print("veszély")
    else:
        return print("mehet")


def main():
    if len(sys.argv)>1:
        hello(sys.argv[1])
    else:
        print("Adjon meg egy nevet")


if __name__=="__main__":
    main()
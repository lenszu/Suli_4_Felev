
import sys


def main():
    Lista=["y","Y","yes"]
    inp = input("Do you really want to quit [y/Y/yes]? ")
    for e in Lista:
        if e == inp:
            print('bye')
            sys.exit(0)
    # for any other input:
    print('The show goes on...')

##############################################################################

if __name__ == "__main__":
    main()
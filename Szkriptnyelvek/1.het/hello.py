import sys

def main():
    if len(sys.argv) > 1:
        if sys.argv[1] == "batman" or sys.argv[1] == "robin":
            print("Veszély")
            
            
            
        else:
            print("Szia "+sys.argv[1]+" mizujs?")
            
    else:
        print("Írjon be egy nevet!")




if __name__ == "__main__":
    main()
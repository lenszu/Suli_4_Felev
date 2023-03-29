import sys
def main():
    a=[]
    if len(sys.argv[1])==10:
        a=[ord(i) for i in sys.argv[1]]
    else:
        print("Hiba!",file=sys.stderr)
    print(a)
    paros=[int(i*1.5) for i in a if i%2==0]
    paratlan=[int(i*-2) for i in a if i%2!=0]
    print(paros)
    print(paratlan)
    print("ketto egyutt:")
    print(paros+paratlan)

if __name__=="__main__":
    main()
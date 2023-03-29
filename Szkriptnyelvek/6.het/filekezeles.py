import sys
def main():
    #olvasás
    f=open("text.txt","r")
    #1
    lines=f.read().splitlines() #\n-ként strippel
    for sor in f:
        print(sor,end="")
        print(sor.rstrip("\n")) #eltünteti az automatikus \n-ezést CSAK JOBB OLDALRÓL 'r'strip() van 'l'strip() is, az meg baloldalról
    #2
    f.seek(0)
    sorok=f.readlines()
    print(sorok)
    f.seek(0)
    sorok_2=[i.rstrip() for i in f.readlines()]
    print(sorok_2)
    f.seek(0)
    s=f.read()
    print(s)
    f.close()
    #írás
    f2=open("text_2.txt","w")
    print("Elso sor",file=f2)
    print("Masodik sor",file=f2)
    print("Harmadik sor",file=f2)
    print("Hiba!..",file=sys.stderr)
    f2.write("cica\n") #nincs \n a végén
    f2.close()
    #append
    f3=open("text_2.txt","a")
    f3.write("ez most append")
    f3.close()

if __name__=="__main__":
    main()
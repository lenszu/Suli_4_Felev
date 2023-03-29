import sys
def main():
    a=[]
    egyes=0
    kettes=0
    harmas=0
    negyes=0
    otos=0
    osszeg=0
    with open("t.txt","r") as f:
        for i in f:
            a.append(i.split(" ")[3].rstrip())
        print(a)
        # print(type(a[0]))
        for i in a:
            osszeg+=float(i)
            if float(i)<2.0:
                egyes+=1
            elif float(i)>=2.0 and float(i)<2.5:
                kettes+=1
            elif float(i)>=2.5 and float(i)<3.0:
                harmas+=1
            elif float(i)>=3.0 and float(i)<3.5:
                negyes+=1
            else:
                otos+=1
        print("Egyes - {0}".format(egyes))
        print("Kettes - {0}".format(kettes))
        print("Harmas - {0}".format(harmas))
        print("Negyes - {0}".format(negyes))
        print("Otos - {0}".format(otos))
        kerekit=osszeg/len(a)
        print(round(kerekit,2))
        


if __name__=="__main__":
    main()
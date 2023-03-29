import sys
def main():
    d=[1,2,3,4,"penis"]
    e=d[:]
    e[0]=100
    print(d)
    print(e)
    for i in range(len(e)):
        print(e[i])
    
    print("cica",end="");print("kutya") #egybe lehet fűzni 
    print(1,2,3,4,5,6,sep=".") #kiiratásnál működik csak
    print("hiba!",file=sys.stderr) #hibakód
    a={0,1,2,3,0,1,2,3,7,-1}
    a=sorted(a)# fuggveny, masolatot keszit és ad vissza
    print(a)
    a=sorted(a,reverse=True) #csokkeno
    print(a)
    a.sort()# eljaras, nem ad vissza semmit, helyben rendez
    print(a)
    a.reverse()
    print(a)
    # sum,min,max
    


if __name__=="__main__":
    main()
import sys
def main():
    a=[1,2,3]
    b=['one','two','three']
    c=list(zip(a,b)) #azért kell a list, hogy iterálható objektumot kapjunk vissza
    d=list(zip(a,b,c))
    print(c)
    print(d)
    e=list(zip("abc","def"))
    print(e)


if __name__=="__main__":
    main()
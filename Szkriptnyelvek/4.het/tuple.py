import sys



def main():
    movie=("Total recall", 1990, 7.5)
    type(movie)
    # parhuzamos ertekadas
    x,y,z=movie
    (x,y)=(1,2)
    #egy elemu tuple
    egy=("f",)
    print(type(egy))
    print(x,y,z)


if __name__=="__main__":
    main()
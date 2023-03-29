import sys
def main():
    sum_1=0
    for i in range(1,101):
        sum_1+=i
    print(sum_1)
    
    print(sum(list(range(101))))
    ######
    parts=[]
    for i in range(1,16):
        parts.append(str(i))
    
    res="".join(parts)
    print(res)
    ######
    c_1="1"
    c_2="2"
    print(int(c_1)+int(c_2))
    
    


if __name__=="__main__":
    main()
import sys
def main():
    s=["aa","bb","cc","dd"]
    s=":".join(s)
    print(s)
    print(len(s))
    print(type(s))
    s=s.split(":")
    print(s)
    print(type(s))
    
    c="aaaa ss          a        v"
    c=c.split()
    print(c)


if __name__=="__main__":
    main()
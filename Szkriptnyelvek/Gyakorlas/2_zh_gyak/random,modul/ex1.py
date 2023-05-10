#! /usr/bin/env python3
def is_prime(n):
    """
    Decide whether a number is prime or not.
    """
    
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    i = 3
    maxi = n**0.5 + 1
    while i <= maxi:
        if n % i == 0:
            return False
        i += 2

    return True

if __name__ == '__main__':
    for i in range(1,50):
        if is_prime(i):
            print(f"{i} prímszám!")
#!/usr/bin/python -tt

def fact(n):
    if (n == 1):
        return 1
    else:
        return n*fact(n-1)

print fact(40)/(fact(20)*fact(20))
#!/usr/bin/python -tt

def fact(n):
    return 1 if n == 1 else n * fact(n - 1)

n = fact(100)
s = 0
while (n > 0):
    s += n % 10
    n /= 10
print s

#!/usr/bin/python -tt

import sys, math

def pentagonal(n):
    return (round(math.sqrt(1 + 24*n))**2 == 1 + 24*n and math.sqrt(1 + 24*n) % 6 == 5)

i = 1
while True:
    n = (3*i*i - i)/2
    for j in range(1, i):
        k = (3*j*j - j)/2
        if pentagonal(n - k) and pentagonal(n + k):
            print n, k, n-k
            sys.exit(0)
    i += 1

#!/usr/bin/python -tt

import math

def pentagonal(n):
    r = (math.sqrt(1 + 24*n) + 1) / 6.0
    return r == int(r)

n, hi = 40755 + 4*143 + 1, 144
while not pentagonal(n):        
    n += 4*hi + 1
    hi += 1
print n

#!/usr/bin/python -tt

def to_binary(n):
    res = ''
    while (n > 0):
        res = str(n & 1) + res
        n >>= 1
    return res

def pal(s):
    return s == s[::-1]

print sum(n for n in range(1, 1000000, 2) if pal(str(n)) and pal(to_binary(n)))

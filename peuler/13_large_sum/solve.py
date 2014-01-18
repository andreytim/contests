#!/usr/bin/python -tt

import os, sys

def add(a, b):
    print '------'
    print a, b
    print int(a) + int(b)
    while(len(a) > len(b)): b = '0' + b
    while(len(b) > len(a)): a = '0' + a
    in_mind = 0
    res = ''
    for i in range(max(len(a), len(b)) - 1, -1, -1):
        next_digit = int(a[i]) + int(b[i]) + in_mind
        if (next_digit > 9):
            next_digit %= 10
            in_mind = 1
        else:
            in_mind = 0
        res = str(next_digit) + res
    if (in_mind == 1):
        res = str(in_mind) + res
    print res
    return res

#print add('37107287533902102798797998220837590246510135740250','46376937677490009712648124896970078050417018260538')
f = open('in.txt')
res = f.readline().strip()
for l in f.readlines():
    res = add(res, l.strip())
f.close()
print res

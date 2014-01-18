#!/usr/bin/python -tt

import sys,os

f = open('in.txt')
m = [ map(lambda x: int(x), l.split(' ')) + [ 1 ] * 3 for l in f.readlines() ]
tmp = [ [ 1 ] * (len(m) + 3) for i in range(0, 3) ]
m = tmp + m + tmp
print m
f.close()

maxs = 0
for i in range(0, len(m)-3):
    for j in range(0, len(m[i])-3):
        maxs = max( m[i][j] * m[i-1][j+1] * m[i-2][j+2] * m[i-3][j+3], maxs )
        maxs = max( m[i][j] * m[i+1][j] * m[i+2][j] * m[i+3][j], maxs )
        maxs = max( m[i][j] * m[i][j+1] * m[i][j+2] * m[i][j+3], maxs )
        maxs = max( m[i][j] * m[i+1][j+1] * m[i+2][j+2] * m[i+3][j+3], maxs )
print maxs 

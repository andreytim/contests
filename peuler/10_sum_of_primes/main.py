#!/usr/bin/python -tt

import sys, math

n = int(sys.argv[1])
sieve = [ False ] * n
res = 2
for i in range(3, len(sieve), 2):
    if not sieve[i]:
        res += i
        for k in range(i, len(sieve), i):
            sieve[k] = True
print res

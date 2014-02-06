#!/usr/bin/python -tt

import itertools

lim = 10**6
sieve = [ True ] * lim
primes = []
for i in range(2, lim):
    if sieve[i]:
        primes.append(i)
        for k in range(i+i, lim, i): sieve[k] = False

def check(p, indices, n):
    pl = list(str(p))
    count = 0
    k = 1 if 0 in indices else 0
    for i in range(k,10):
        for idx in indices:
            pl[idx] = chr(i + ord('0'))
        if sieve[int(''.join(pl))]: count += 1
    return count >= n

def worked(p, n):
    indices = [ i for i, d in enumerate(str(p)) if d == '0' or d == '1' ]
    for i in range(1, len(indices) + 1):
        for comb in itertools.combinations(indices, i):
            if check(p, comb, n): return True
    return False

for p in primes:
    if worked(p, 8): 
        print p
        break


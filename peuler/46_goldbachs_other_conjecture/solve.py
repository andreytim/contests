#!/usr/bin/python -tt

import math

LIM = 10**7
sieve = [ True ] * LIM
primes = []
for i in range(2, LIM):
    if sieve[i]:
        primes.append(i)
        for k in range(i+i,LIM,i): sieve[k] = False

for k in range(3, LIM, 2):
    if not sieve[k]:
        p = primes[1]
        i = 2
        while p < k-1:
            sqr = (k - p) / 2
            if int(math.sqrt(sqr)) == math.sqrt(sqr): 
                #print '%d = %d + 2*%.2f^2' % (k, p, math.sqrt(sqr))
                break
            p = primes[i]
            i += 1
        if p > k-2:
            print k
            break
            

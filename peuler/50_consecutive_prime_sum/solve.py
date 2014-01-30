#!/usr/bin/python -tt

lim = 10**6
primes = []
sieve = [0]*lim
for i in range(2,lim):
    if sieve[i] == 0: 
        primes.append(i)
        for k in range(i+i,lim,i): sieve[k] = 1

l, p = 21, 0
while sum(primes[0:l]) < lim:
    l += 2
    has_prime = False
    for i in range(0,len(primes)-l):
        s = sum(primes[i:i+l])
        if s >= lim: break
        if sieve[s] == 0: 
            p = s
            break
print l, p

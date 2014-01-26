#!/usr/bin/python -tt

lim = 10**4
primes = []
sieve = [0]*lim
for i in range(2,lim):
    if sieve[i] == 0:
        if i > 1000: primes.append(i)
        sieve[i*2::i] = [ 1 for x in range(i*2,lim,i) ]
for p in primes:
    if p > lim - 6660: break
    p1, p2 = p + 3330, p + 6660
    if sieve[p1] == 0 and sieve[p2] == 0 and \
            sorted(str(p)) == sorted(str(p1)) and \
            sorted(str(p1)) == sorted(str(p2)):
                print p, p1, p2

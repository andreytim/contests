#!/usr/bin/python -tt

LIM = 10**6
primes = []
sieve = [ True ]*LIM
for i in range(2,LIM):
    if sieve[i]:
        primes.append(i)
        for k in range(i*i,LIM,i): sieve[k] = False

def has_four_distinct(n):
    count = 0
    k = n
    for p in primes:
        if p > n: break
        if n % p == 0:
            n /= p
            count += 1
    return count == 4

fd = [ False ] * LIM
for n in range(1,LIM):
    if not sieve[n]:
        fd[n] = has_four_distinct(n)
    if fd[n] and fd[n-1] and fd[n-2] and fd[n-3]:
        print n, n-1, n-2, n-3
        break

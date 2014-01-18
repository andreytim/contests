#!/usr/bin/python -tt

limit = 1000000
sieve = [ True ] * limit
primes = []
for i in range(2, limit):
    if sieve[i]:
        primes.append(i)
        for k in range(i+i, limit, i):
            sieve[k] = False

count = 0
for p in primes:
    p_rotated = p
    if p_rotated > 10:
        dim = 10**(len(str(p)) - 1)
        p_rotated = p % dim * 10 + p / dim
        while (p_rotated != p):
            if not sieve[p_rotated]:
                break
            p_rotated = p_rotated % dim * 10 + p_rotated / dim
    if p_rotated == p:
        count += 1
print count


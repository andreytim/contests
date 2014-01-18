#!/usr/bin/python -tt

import itertools, math

primes_cache = { 2:True }
def is_prime(p):
    if not p in primes_cache:
        i = 2
        prime = True
        while i < math.sqrt(p) + 1:
            if p % i == 0:
                prime = False
                break
            i += 1
        primes_cache[p] = prime
    return primes_cache[p]

def is_truncatable_prime(p):
    if p < 10:
        return False
    dim = 10
    if not is_prime(p):
        return False
    while (dim < p):
        if not is_prime(p / dim) or not is_prime(p % dim):
            return False
        dim *= 10
    return True

s = 0
for i in range(2,7):
    for comb in itertools.product('123579', repeat=i):
        if comb[0] != '1' and comb[i - 1] != '1' and comb[0] != '9' and comb[i - 1] != '9' and is_truncatable_prime(int(''.join(comb))):
            print comb
            s += int(''.join(comb))
print s

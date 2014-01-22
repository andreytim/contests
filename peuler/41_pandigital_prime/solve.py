#!/usr/bin/python -tt

import math, itertools, sys

def is_prime(n):
    for i in range(3, int(math.sqrt(n) + 1), 2):
        if n % i == 0: return False
    return True

wrong = set(['2', '4', '5', '6'])
for t in itertools.permutations("7654321"):
    if not t[len(t) - 1] in wrong and is_prime(int(''.join(t))):
        print ''.join(t)
        sys.exit(0)

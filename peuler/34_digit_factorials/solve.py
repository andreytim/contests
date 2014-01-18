#!/usr/bin/python -tt

def fact(n):
    return 1 if n < 2 else n * fact(n-1)
facts = [ fact(i) for i in range(0, 10) ]
print facts

cache = {}
def sum_fd(n):
    key = ''.join(sorted(str(n)))
    if not key in cache:
        cache[key] = sum(facts[ord(ch) - ord('0')] for ch in key) 
    return cache[key]

print sum(i for i in range(10,10000000) if sum_fd(i) == i)

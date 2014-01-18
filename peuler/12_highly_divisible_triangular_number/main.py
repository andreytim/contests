#!/usr/bin/python -tt

import math

def number_of_divisors(n):
    num = 0
    for i in range(3, int(math.sqrt(n + 1)) + 1):
        if (n % i == 0 or (n + 1) % i == 0):
            num += 1
    return num * 2 + 4

n = 0
i = 10
while (n < 500): 
    i += 1
    n = number_of_divisors(i)
    print n
print n

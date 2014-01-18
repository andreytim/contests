#!/usr/bin/python -tt

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def simplify(a, b):
    d = gcd(a, b)
    return (a/d, b/d)

fractions = []
for a in range(10,100):
    if a % 10 == 0:
        continue
    b = a + 1
    while (b / 10 == a / 10):
        if (simplify(a, b) == simplify(a % 10, b % 10)):
            fractions.append((a, b))
        b += 1
    b = a + 10
    while (b < 100):
        if (simplify(a, b) == simplify(a / 10, b / 10)):
            fractions.append((a, b))
        b += 10
    if (a / 10 < a % 10):
        b = (a % 10) * 10;
        while (b / 10 == a % 10):
            if (simplify(a,b) == simplify(a / 10, b % 10)):
                fractions.append((a, b))
            b += 1
m = reduce(lambda acc, t: (acc[0]*t[0], acc[1]*t[1]), fractions, (1, 1))
print simplify(m[0], m[1])

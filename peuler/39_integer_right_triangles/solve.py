#!/usr/bin/python -tt

for i in range(1, 1001):
    count = 0
    for a in range(1, i/2):
        for b in range(1, i - a):
            if a*a + b*b == (i - a - b)*(i - a - b):
                count += 1
    print i, count

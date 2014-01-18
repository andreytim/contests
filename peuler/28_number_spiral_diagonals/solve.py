#!/usr/bin/python -tt

total, b = 1, 3
for i in range(2,1001,2):
    total += 2*(3*i + 2*b)
    b += 2*(2*i + 1)
print total

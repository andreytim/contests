#!/usr/bin/python -tt

def sum_of_digit_fifth_powers(n):
    res = 0
    while (n > 0):
        res += (n % 10)**5
        n /= 10
    return res

total = 0
for i in range(10,10000000):
    if i == sum_of_digit_fifth_powers(i):
        total += i
        print i
print total

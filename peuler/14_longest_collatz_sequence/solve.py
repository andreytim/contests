#!/usr/bin/python -tt

def get_collatz_seq_length(n):
    res = 0
    while (n != 1):
        if (n & 1 == 0):
            n >>= 1
        else:
            n = 3*n + 1
        res += 1
    return res

maxl = 0
maxn = 0
for i in range(pow(2,19),1000000):
    l = get_collatz_seq_length(i)
    if (l > maxl):
        print i, l
        maxl = l
        maxn = i
print maxn

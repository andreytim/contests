#!/usr/bin/python -tt

maxn = 0
for i in range(5123, 9877):
    n = i * 100000 + i * 2
    if ''.join(sorted(str(n))) == '123456789':
        maxn = max(n, maxn)
for i in range(123, 330):
    n = i * 1000000 + i * 2000 + i * 3
    if ''.join(sorted(str(n))) == '123456789':
        maxn = max(n, maxn)
for i in range(25, 33):
    n = i * 10000000 + i * 200000 + i * 3000 + i * 4
    if ''.join(sorted(str(n))) == '123456789':
        maxn = max(n, maxn)
print maxn
        

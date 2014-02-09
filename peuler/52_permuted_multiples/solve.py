#!/usr/bin/python -tt

def cool(n):
    return str(n)[0] == '1' and sorted(str(n)) == sorted(str(n*2)) == sorted(str(n*3)) == \
        sorted(str(n*4)) == sorted(str(n*5)) == sorted(str(n*6))

n = 100
while not cool(n): n += 1
print n

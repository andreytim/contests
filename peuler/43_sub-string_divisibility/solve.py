#!/usr/bin/python -tt

import itertools

s = 0
for t in itertools.permutations("0123456789"):
    if t[0] != '0' and int(''.join(t[-3:])) % 17 == 0 and \
           int(''.join(t[-4:-1])) % 13 == 0 and \
           int(''.join(t[-5:-2])) % 11 == 0 and \
           int(''.join(t[-6:-3])) % 7 == 0 and \
           int(''.join(t[-7:-4])) % 5 == 0 and \
           int(''.join(t[-8:-5])) % 3 == 0 and \
           int(''.join(t[-9:-6])) % 2 == 0:
        s += int(''.join(t))
print s

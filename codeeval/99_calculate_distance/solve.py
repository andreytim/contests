#!/usr/bin/python -tt

import sys, math

f = open(sys.argv[1])
for l in f.readlines():
    a, b = l.strip()[1:].split(" (")
    a1, a2 = map( lambda x: int(x), a[:-1].split(", "))
    b1, b2 = map( lambda x: int(x), b[:-1].split(", "))
    print int(math.sqrt((a1-b1)**2 + (a2-b2)**2))
f.close()

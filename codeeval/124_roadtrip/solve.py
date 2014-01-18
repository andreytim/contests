#!/usr/bin/python -tt

import sys

f = open(sys.argv[1])
for l in f.readlines():
    cities = [0] + sorted([ int(x[:-1].split(',')[1]) for x in l.strip().split(' ') ])
    print ','.join([ str(cities[i] - cities[i - 1]) for i in range(1, len(cities)) ])
f.close()

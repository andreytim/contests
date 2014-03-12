#!/usr/bin/python

import sys

f = open(sys.argv[1], 'r')
for l in f.readlines():
    counts = [0] * 100
    seq = [ int(s) for s in l.strip().split(',') ]
    m = None
    for n in seq:
        counts[n] += 1
        if counts[n] > len(seq) / 2:
            m = n
            break
    print str(m)

f.close()

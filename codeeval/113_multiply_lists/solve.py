#!/usr/bin/python -tt

import sys

f = open(sys.argv[1])
for l in f.readlines():
    l1, l2 = l.strip().split(' | ')
    l1 = l1.split(' ')
    print ' '.join([ str(int(l1[i]) * int(e)) for i, e in enumerate(l2.split(' ')) ])
f.close()

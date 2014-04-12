#!/usr/bin/python -tt

import sys

f = open(sys.argv[1], 'r')
i = 0
for l in f.readlines():
    print '%d: %s' % (i, l.strip())
    i += 1
f.close()

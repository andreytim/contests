#!/usr/bin/python -tt

import sys, re

f = open(sys.argv[1], 'r')
for l in f.readlines():
    l1, l2 = l.strip().split(',')
    if not l2:
        print 'true' if not l1 else 'false'
    else:
        l2 = '.*' + l2.replace('*','.*').replace('\\.','\\') + '.*'
        print 'true' if re.compile(l2).match(l1) else 'false'
f.close()

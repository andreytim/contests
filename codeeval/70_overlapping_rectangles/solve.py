#!/usr/bin/python -tt

import sys

f = open(sys.argv[1])
for l in f.readlines():
    coords = map( lambda x: int(x), l.split(','))
    print "False" if coords[0] > coords[6] or coords[1] < coords[7] or coords[2] < coords[4] or coords[3] > coords[5] else "True"
f.close()

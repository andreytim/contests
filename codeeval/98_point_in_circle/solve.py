#!/usr/bin/python -tt

import sys

f = open(sys.argv[1], 'r')
for l in f.readlines():
    data = l.strip().split(';')
    center = [ float(x) for x in  data[0][data[0].find('(') + 1:-1].split(', ') ]
    point = [ float(x) for x in  data[2][data[2].find('(') + 1:-1].split(', ') ]
    radius = float(data[1][data[1].find(': ') + 1:]) 
    #print center, point, radius
    if (center[0] - point[0])**2 + (center[1] - point[1])**2 <= radius**2:
        print 'true'
    else:
        print 'false'
f.close()

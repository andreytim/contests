#!/usr/bin/python -tt

import sys

def fits(hole, brick):
    hole_a = abs(hole[0][0] - hole[1][0])
    hole_b = abs(hole[0][1] - hole[1][1])
    #print 'hole: %dx%d' % (hole_a, hole_b)
    for i in range(0,3):
        side_a = abs(brick[1][i] - brick[2][i])
        side_b = abs(brick[1][(i + 1) % 3] - brick[2][(i + 1) % 3])
        #print 'brick_%d: side_%d=%dx%d' % (brick[0], i, side_a, side_b)
        if max(side_a, side_b) <= max(hole_a, hole_b) and \
                min(side_a, side_b) <= min(hole_a, hole_b): return True
    return False

f = open(sys.argv[1], 'r')
for l in f.readlines():
    strhole, strbricks = l.strip().split('|')
    hole = [ map(lambda x: int(x), p[1:-1].split(',')) for p in strhole.split(' ') ]
    strbricks2 = [ b[1:-1].split(' ') for b in strbricks.split(';') ]
    bricks = [ (int(b[0]), map(lambda x: int(x), b[1][1:-1].split(',')), 
        map(lambda x: int(x), b[2][1:-1].split(',')) ) for b in strbricks2 ]
    good = []
    for brick in bricks:
        if fits(hole, brick): good.append(str(brick[0]))
    if len(good) > 0: print ','.join(good)
    else: print '-'
f.close()

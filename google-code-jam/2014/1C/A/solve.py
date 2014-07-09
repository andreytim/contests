#!/usr/bin/python

import sys, math

powers = [ 2.0**i for i in range(1,41) ]

def solve(P, Q):
    g = 1
    for i in powers:
        curr = P * i / Q
        if curr - math.floor(curr) == 0:
            while Q % i != 0:
                i /= 2
                g -= 1
            return g
        g += 1
    return 'impossible'

def main():
    f = open(sys.argv[1], 'r')
    T = int(f.readline().strip())
    for i in range(1, T + 1):
        line = f.readline()
        P, Q = [ int(s) for s in line.strip().split('/') ]
        print 'Case #%d: %s' % (i, solve(P, Q))

if __name__ == '__main__':
    main()

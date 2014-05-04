#!/usr/bin/python

import sys, math

def deg2(a):
    d = 0
    while (a > 0):
        d += 1
        a >>= 1
    return d

def solve_test_case(A, B, K):
    degA = deg2(A)
    degB = deg2(B)
    for i in range(0, 1000000):
        #degK = deg2(K)
        print i
    return 0

def main():
    f = open(sys.argv[1], 'r')
    n = int(f.readline().strip())
    for i in range(1,n+1):
        line = f.readline()
        A, B, K = (int(s) for s in line.strip().split(' '))
        print 'Case #%d: %d' % (i, solve_test_case(A, B, K))

if __name__ == '__main__':
    main()

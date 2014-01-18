#!/usr/bin/python -tt

import sys

def solve(n):
    res = 0
#    print n
    for i in range(1,n+1):
        for j in range(i+1,n+1):
#            print str(i), str(j)
            res += i*j*2
    return res

def main():
    n = int(sys.argv[1])
    print "Sum sqaure diff = ", solve(n)

main()

#!/usr/bin/python

import sys

def solve():
    return ''

def main():
    f = open(sys.argv[1], 'r')
    T = int(f.readline().strip())
    for i in range(1, T + 1):
        print 'Case #%d: %s' % (i, solve())

if __name__ == '__main__':
    main()

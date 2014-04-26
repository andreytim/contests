#!/usr/bin/python

import sys

def sort_by_char(i):
    return lambda s: s[0:i+1]

def switch(devices, i):
    for d in devices:
        d[i] = '1' if d[i] == '0' else '0'
    return devices

def solve_test_case(outlets, devices):
    switches = 0
    possible = True
    i = 0
    while i < len(outlets[0]):
        outlets = sorted(outlets, key=sort_by_char(i))
        devices = sorted(devices, key=sort_by_char(i))
        print '\n'.join(['---'] + [ ''.join(outlets[k]) + ' ' + ''.join(devices[k]) for k in range(0, len(outlets)) ])
        ocol = ''.join(s[i] for s in outlets)
        dcol = ''.join(s[i] for s in devices)
        if ocol != dcol:
            devices = sorted(switch(devices, i))
            dcol = ''.join(s[i] for s in devices)
            if ocol != dcol:
                return 'NOT POSSIBLE'
            else:
                switches += 1
        i += 1
    print '\n'.join(['---'] + [ ''.join(outlets[k]) + ' ' + ''.join(devices[k]) for k in range(0, len(outlets)) ])
    return str(switches)

def main():
    f = open(sys.argv[1], 'r')
    n = int(f.readline().strip())
    for i in range(1,n+1):
        f.readline()
        outlets = [ list(s) for s in f.readline().strip().split(' ') ]
        devices = [ list(s) for s in f.readline().strip().split(' ') ]
        print 'Case #%d: %s' % (i, solve_test_case(outlets, devices))

if __name__ == '__main__':
    main()

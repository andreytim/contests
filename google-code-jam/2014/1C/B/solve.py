#!/usr/bin/python

import sys

def check_valid(string):
    visited = set()
    curr = string[0]
    visited.add(curr)
    for i in range(1, len(string)):
        if (curr != string[i]):
            if string[i] in visited:
                return False
            else:
                visited.add(string[i])
                curr = string[i]
    return True

def check_letters(str1, str2):
    set1 = set(ch for ch in str1)
    set2 = set(ch for ch in str2)
    edge1 = set([ str1[0], str1[-1] ])
    edge2 = set([ str2[0], str2[-1] ])
    for ch in set1:
        if ch in set2 and not (ch in edge1 and ch in edge2):
            return False
    return True

def recursiveTry(currStr, carts):
    if not check_valid(currStr):
        return 0
    elif not carts:
        return 1
    total = 0
    for i in range(0, len(carts)):
        if check_letters(currStr, carts[i]):
            total += recursiveTry(currStr + carts[i], carts[:i] + carts[i+1:])
    return total

def remove_dups(s):
    res = []
    prev = ' '
    for ch in s:
        if prev != ch:
            res.append(ch)
            prev = ch
    return ''.join(res)

def solve(N, strings):
    total = 0
    for i in range(0, len(strings)):
        total += recursiveTry(strings[i], strings[:i] + strings[i+1:])
    return total

def main():
    f = open(sys.argv[1], 'r')
    T = int(f.readline().strip())
    for i in range(1, T + 1):
        N = int(f.readline().strip())
        strings = [ remove_dups(s) for s in f.readline().strip().split(' ') ]
        print 'Case #%d: %d' % (i, solve(N, strings))

if __name__ == '__main__':
    main()

#!/usr/bin/python -tt

import sys

f = open(sys.argv[1])
for l in f.readlines():
    lst = l.strip().split(' ')
    if int(lst[-1]) < len(lst):
        print lst[len(lst) - 1 - int(lst[-1])]
f.close()

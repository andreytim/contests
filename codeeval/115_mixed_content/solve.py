#!/usr/bin/python -tt

import sys, re

rwords, rdigits = r'([a-zA-Z]+)', r'([0-9]+)'
f = open(sys.argv[1])
for l in f.readlines():
    print '|'.join([ l for l in [','.join(re.findall(rwords, l)), ','.join(re.findall(rdigits, l))] if l ])
f.close()

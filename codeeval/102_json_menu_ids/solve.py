#!/usr/bin/python -tt

import sys, json

f = open(sys.argv[1])
for l in f.readlines():
    if l.strip():
        decoded = json.loads(l.strip())
        print sum([ item["id"] for item in decoded["menu"]["items"] if item and "label" in item ])
f.close()

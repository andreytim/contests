#!/usr/bin/python -tt

import sys

f = open(sys.argv[1])
for l in f.readlines():
    if l.strip():
        code, cypher_str = l.strip().split("|")
        cypher = [ int(x) for x in cypher_str.strip().split(" ") ]
        res = ""
        for i in range(0, len(cypher)):
            res += code[cypher[i] - 1]
        print res
f.close()

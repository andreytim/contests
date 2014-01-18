#!/usr/bin/python -tt

import sys, re

emailre = r'^([a-zA-Z0-9._%+-]+|".+")@[a-zA-Z0-9.-]+\.?[a-zA-Z]*$'
f = open(sys.argv[1])
for l in f.readlines():
    print 'true' if re.match(emailre, l.strip()) else 'false'
f.close()

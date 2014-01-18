#!/usr/bin/python -tt

import sys

def hidden(ch):
    if ch in 'abcdefghij':
        return str(ord(ch) - ord('a'))
    elif ch in '0123456789':
        return str(ch)
    return ''

f = open(sys.argv[1])
for l in f.readlines():
    st = ''
    for ch in l.strip():
        st += hidden(ch)
    print (st if st else 'NONE')
f.close()

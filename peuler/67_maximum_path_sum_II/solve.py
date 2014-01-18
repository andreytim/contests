#!/usr/bin/python -tt

f = open('in.txt')
prev_level = [ 0, 0 ]
for l in f.readlines():
    next_level = []
    for i, n in enumerate(map( lambda x: int(x), l.strip().split(' ') )):
        next_level.append(max( n + prev_level[i], n + prev_level[i + 1] ))
    prev_level = [ 0 ] + next_level + [ 0 ]
print max(prev_level)
f.close()

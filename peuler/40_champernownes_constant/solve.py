#!/usr/bin/python -tt

limit = 1000002
strs = '0'
i = 1
while (len(strs) < limit):
    strs += str(i)
    i += 1
print str(int(strs[1]) * int(strs[10]) * int(strs[100]) * int(strs[1000]) * int(strs[10000]) * int(strs[100000]) * int(strs[1000000]))

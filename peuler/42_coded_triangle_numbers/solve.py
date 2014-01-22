#!/usr/bin/python -tt

triangles = [ False ] * 1000
n = 1
while (n*(n+1)/2 < 1000): 
    triangles[n*(n+1)/2] = True
    n += 1
f = open('words.txt', 'r')
count = 0
for word in f.readline().translate(None,'"').split(','):
    if triangles[sum(ord(ch) - ord('A') + 1 for ch in word.upper())]:
        count += 1
print count

#!/usr/bin/python -tt

import sys, re

def convert(line, goal):
  result = []
  j = 0
  for i in range(0, len(goal)):
    while j < len(line) and line[j].find(goal[i]) == -1: 
      result.append(''.join(['_'] * len(line[j])));
      j += 1
    if j == len(line): return 'I cannot fix history'
    idx = line[j].find(goal[i])
    if idx >= 0:
      result.append(''.join(
        [ '_' if k < idx or k >= idx + len(goal[i]) else ch for k, ch in enumerate(line[j]) ]))
      j += 1
  while j < len(line): 
    result.append(''.join(['_'] * len(line[j])))
    j += 1
  return ' '.join(result)

def main():
  f = open(sys.argv[1], 'r')
  for l in f.readlines():
    args = l.strip().split(';')
    print convert(re.split(r'\s+', args[0]), re.split(r'\s+', args[1]))
  f.close()

if __name__ == '__main__':
  main()

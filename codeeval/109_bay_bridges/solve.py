#!/usr/bin/python -tt

import sys, re
from collections import namedtuple

lonlat = r'[0-9.-]{9,11}'
Bridge = namedtuple('Bridge', 'lat1 lon1 lat2 lon2 idx')

def solve(bridges):
  rbridges = sorted(bridges, key=lambda b: b.lon2)
  # DP LCS
  dm = [[0] * (len(bridges) + 1) for i in range(0, len(bridges) + 1)]
  for i in range(1, len(bridges) + 1):
    for j in range(1, len(bridges) + 1):
      if bridges[i-1].idx == rbridges[j-1].idx:
        dm[i][j] = dm[i-1][j-1] + 1
      else:
        dm[i][j] = max(dm[i-1][j], dm[i][j-1])
  # backtracking restore
  result = []
  i, j = len(bridges), len(bridges)
  while i > 0 and j > 0:
    if bridges[i-1] == rbridges[j-1]:
      result.append(bridges[i-1].idx)
      i -= 1; j -= 1
    else:
      if dm[i-1][j] < dm[i][j-1]: j -= 1
      else: i -= 1
  return '\n'.join(str(b) for b in sorted(result))

def main():
  f = open(sys.argv[1], 'r')
  bridges = []
  for l in f.readlines():
    b = int(l[:l.find(':')])
    lat1, lon1, lat2, lon2 = (float(d) for d in re.findall(lonlat, l))
    bridges.append(Bridge(lat1, lon1, lat2, lon2, b))
  print solve(sorted(bridges, key=lambda b: b.lon1))
  f.close()

if __name__ == '__main__':
  main()

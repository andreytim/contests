#!/usr/bin/python -tt

import sys, re

ip4dec = r'(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})'
ip4hex = r'(0x[A-Fa-f0-9]{1,2}\.0x[A-Fa-f0-9]{1,2}\.0x[A-Fa-f0-9]{1,2}\.0x[A-Fa-f0-9]{1,2})'
ip4oct = r'(0[0-7]{1,3}\.0[0-7]{1,3}\.0[0-7]{1,3}\.0[0-7]{1,3})'
ip4bin = r'([01]{8}\.[01]{8}\.[01]{8}\.[01]{8})'
ipdec = r'([1-9]\d{7,})'
iphex = r'(0x[A-Fa-f0-9]{6,})'
ipoct = r'(0[1-7][0-7]{6,10})'
ipbin = r'([01]{24,32})'

def get_ip4dec(line):
  res = []
  for s in re.findall(ip4dec, line):
    lval = 0
    for i, oct in enumerate(s.split('.')):
      lval += (int(oct) << (3-i)*8)
    res.append((s, lval))
  return res

def get_ip4oct(line):
  res = []
  for s in re.findall(ip4oct, line):
    lval = 0
    for i, oct in enumerate(s.split('.')):
      decoct = 0
      for d in range(0,len(oct)):
        decoct = decoct * 8 + int(oct[d])
      lval += (int(decoct) << (3-i)*8)
    res.append((s, lval))
  return res

hexm = { '0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, 
    'A':10, 'B':11, 'C':12, 'D':13, 'E':14, 'F':15, 'a':10, 'b':11, 'c':12, 'd':13, 'e':14, 'f':15 }
def get_ip4hex(line):
  res = []
  for s in re.findall(ip4hex, line):
    lval = 0
    for i, oct in enumerate(s.split('.')):
      decoct = 0
      for d in range(2,len(oct)):
        decoct = decoct * 16 + hexm[oct[d]]
      lval += (int(decoct) << (3-i)*8)
    res.append((s, lval))
  return res

def get_ip4bin(line):
  res = []
  for s in re.findall(ip4bin, line):
    lval = 0
    for i, oct in enumerate(s.split('.')):
      decoct = 0
      for d in range(0,len(oct)):
        decoct = decoct * 2 + int(oct[d])
      lval += (int(decoct) << (3-i)*8)
    res.append((s, lval))
  return res

def get_ipbin(line):
  res = []
  for s in re.findall(ipbin, line):
    lval = 0
    for d in range(0,len(s)):
      lval = lval * 2 + int(s[d])
    res.append((s, lval))
  return res

def get_iphex(line):
  res = []
  for s in re.findall(iphex, line):
    lval = 0
    for d in range(2,len(s)):
      lval = lval * 16 + hexm[s[d]]
    res.append((s, lval))
  return res

def get_ipoct(line):
  res = []
  for s in re.findall(ipoct, line):
    lval = 0
    for d in range(0,len(s)):
      lval = lval * 8 + int(s[d])
    res.append((s, lval))
  return res

def get_ipdec(line):
  res = []
  for s in re.findall(ipdec, line):
    res.append((s, int(s)))
  return res

def long_to_ipv4(ipl):
  res = ''
  while (ipl > 0):
    res = '.' + str(ipl % 256) + res
    ipl /= 256
  return res[1:]

f = open(sys.argv[1], 'r')
ips = []
for l in f.readlines():
  l = l.strip()
  ips += get_ip4dec(l) + get_ip4oct(l) + get_ip4hex(l) + get_ip4bin(l)
  ips += get_ipbin(l) + get_iphex(l) + get_ipoct(l) + get_ipdec(l)
f.close()
minip = get_ip4dec('1.0.0.0')[0][1]
maxip = get_ip4dec('255.255.255.254')[0][1]
counts = {}
for d in filter(lambda x: x[1] >= minip and x[1] <= maxip, ips):
  if not d[1] in counts:
    counts[d[1]] = 0
  counts[d[1]] += 1
maxes = sorted(counts.items(), key=lambda x:x[1], reverse=True)
print ' '.join([ long_to_ipv4(ip) for ip in sorted(m[0] for m in maxes if m[1] == maxes[0][1])])

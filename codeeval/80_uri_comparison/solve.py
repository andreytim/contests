#!/usr/bin/python -tt

import sys

reserved = set(['/','$','&','?',':','@','+','#','=','.'])

def hex_convert(uri):
   new_str = ''
   i = 0
   while (i < len(uri)):
        if uri[i] == '%' and i < len(uri)-2 and \
                ((uri[i+1].isalpha()) or uri[i+1].isdigit()) and \
                ((uri[i+2].isalpha()) or uri[i+2].isdigit()):
            new_str += chr(int(uri[i+1:i+3], 16))
            i += 3
        else:
            new_str += uri[i]
            i += 1
   return new_str
            

f = open(sys.argv[1], 'r')
for l in f.readlines():
    uris = l.strip().split(';')
    for i in range(0, len(uris)):
        uris[i] = uris[i].replace(':80/', '/')
        if uris[i].endswith(':80'):
            uris[i] = uris[i][:-3]
        uris[i] = hex_convert(uris[i])
    #print uris[0].lower().strip(), uris[1].lower().strip()
    print '%r' % (uris[0].lower().strip() == uris[1].lower().strip())
f.close()

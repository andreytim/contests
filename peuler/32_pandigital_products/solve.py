#!/usr/bin/python -tt

print sum(set(i*j for i in range(1,100) for j in range(100,10000/i) if ''.join(sorted(str(i) + str(j) + str(i*j))) == "123456789" ))

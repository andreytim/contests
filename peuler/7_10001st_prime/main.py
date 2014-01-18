import sys, math

def solve(n):
    border = 13
    if n > 6:
        border = int(math.floor((math.log(n) + math.log(math.log(n))) * n))
    sieve = [False]*(border + 1)
    count = 0
    for i in range(2,len(sieve)):
        if not sieve[i]:
            count += 1
            if (count == n):
                return i
            for j in range(i,len(sieve),i):
                sieve[j] = True

def main():
    n = int(sys.argv[1])
    print solve(n)

main()

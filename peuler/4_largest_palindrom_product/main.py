import sys, os

def check_palindrom(n):
    digits = []
    while (n > 0):
        digits.append(n % 10)
        n /= 10
    # print digits
    for i in range(0, len(digits)/2):
        if (digits[i] != digits[len(digits) - i - 1]):
            return False
    return True

def find():
    max_pal = 0
    for i in range(100,1000):
        for j in range(100,1000):
            if (check_palindrom(i*j)):
                max_pal = max(max_pal, i*j)
    print "Max pal: " + str(max_pal)

print "23412: " + str(check_palindrom(23412))
print "1: " + str(check_palindrom(1))
print "32123: " + str(check_palindrom(32123))
print "321123: " + str(check_palindrom(321123))
find()

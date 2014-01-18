#!/usr/bin/python -tt

def rec_sum(n, coins, count):
    if not coins or n < 0:
        return 0
    elif n == 0:
        return count + 1
    else:
        return rec_sum(n, coins[1:], count) + rec_sum(n - coins[0], coins, count)

print rec_sum(200, [200, 100, 50, 20, 10, 5, 2, 1], 0)

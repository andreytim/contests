#!/usr/bin/python -tt

def is_leap(y):
    return y % 400 == 0 or (y % 100 != 0 and y % 4 == 0)

month_days = [ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 ]
def get_days_of_month(m, y):
    return 29 if m == 1 and is_leap(y) else month_days[m]

y, m, shift, total_cnt = 1901, 0, 2, 0
while (y < 2001):
    if (shift % 7 == 0):
        total_cnt += 1
        print m + 1, y
    shift += get_days_of_month(m, y)
    m = m + 1 if m < 11 else 0
    if m == 0:
        y += 1
print total_cnt

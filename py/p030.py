#!/usr/bin/env python

# Project Euler
# Problem 30
#
# Find the sum of all the numbers that can be written as the sum of
# fifth powers of their digits.

def fifth_power_eq(n):
    sum = 0
    i = n
    while i:
        sum += (i % 10) ** 5
        i //= 10
    return sum == n

def p030():
    nums = []
    for n in xrange(2, 999999):
        if fifth_power_eq(n):
            nums.append(n)
    return sum(nums)

if __name__=='__main__':
    print p030()

#!/usr/bin/env python

# Project Euler
# Problem 36
#
# Find the sum of all numbers less than one million, which are
# palindromic in base 10 and base 2.

def palindromic10(n):
    if n % 10 == 0:
        return False
    s = str(n)
    return s == s[::-1]

def palindromic2(n):
    x = n
    r = 0
    while x:
        r = (r << 1) | (x & 1)
        x >>= 1
    return r == n

def p036():
    return sum((n for n in xrange(1,1000000,2) if palindromic10(n) and palindromic2(n)))

if __name__=='__main__':
    print p036()

#!/usr/bin/env python

# Project Euler
# Problem 48
#
# Find the last ten digits of 1^1 + 2^2 + ... + 1000^1000.

def p048():
    sum = 0
    for i in xrange(1,1001):
        sum = (sum + i**i) % 10000000000
    return sum

if __name__=='__main__':
    print p048()

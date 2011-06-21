#!/usr/bin/env python

# Project Euler
# Problem 21
#
# Evaluate the sum of all the amicable numbers under 10000.

from utils import proper_divisors

def d(n):
    divs = proper_divisors(n)
    if divs:
        return sum(divs)
    else:
        return 1

def p021():
    total = 0
    known = {}
    for i in xrange(2, 10000):
        d_i = d(i)
        if d_i == i or d_i == 1:
            continue
        known[i] = d_i
        if d_i not in known:
            known[d_i] = d(d_i)
        if i == known[d_i]:
            total += i
    return total

if __name__=='__main__':
    print p021()

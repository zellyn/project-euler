#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 92
#
# Investigating a square digits number chain with a surprising
# property.

KNOWN = {89:True, 1:False, 0:False}
def ends_at_89(n):
    if n not in KNOWN:
        KNOWN[n] = ends_at_89(sum(int(d)**2 for d in str(n)))
    return KNOWN[n]

SUMS = [x**2 for x in xrange(0,10)]
SUMS2 = [x + y for x in SUMS for y in SUMS]

def s_length(n, first=True):
    if n==2:
        return SUMS2
    else:
        return (ss + s for s in SUMS for ss in s_length(n-1, False))

def p092():
    l = [ends_at_89(x) for x in xrange(2,81*7+1)]
    result = sum(KNOWN[n] for n in s_length(7))
    return result

if __name__=='__main__':
    print p092()

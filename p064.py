#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 64
#
# How many continued fractions for N ≤ 10000 have an odd period?

from math import sqrt

from utils import gcd

def c_sqrt(n):
    """
    http://www.mcs.surrey.ac.uk/Personal/R.Knott/Fibonacci/cfINTRO.html#sqrtalgsalg
    """
    s = int(sqrt(n))
    tup = ()
    if s*s==n:
        return (s, tup)

    r = 0
    d = 1
    sn = s

    while True:
        # (√n + r) / d = sn + 1/x
        # rn = sn * d - r
        # x = d / (√n - rn) * (√n + rn)/(√n + rn)
        # x = d (√n + rn) / n - rn**2
        # dn = (n - rn**2) / d
        # r,d = rn,dn
        
        rn = sn * d - r
        dn = (n - rn*rn) / d
        r,d = rn,dn
        sn = int(s+r) // d

        if d > 1:
            tup = tup + (sn,)
        else:
            tup = tup + (2 * s,)
            return (s,tup)

def p064():
    LIMIT = 10000
    count = 0
    for i in xrange(2,LIMIT+1):
        c_s = c_sqrt(i)
        if len(c_s[1]) % 2:
            count += 1
    return count

if __name__=='__main__':
    print p064()

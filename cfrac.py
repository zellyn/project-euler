#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Continued fraction functions

from math import sqrt

def cf_sqrt(n):
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

def cf_e():
    yield 2
    i = 2
    while True:
        yield 1
        yield i
        yield 1
        i += 2

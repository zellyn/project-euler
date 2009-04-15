#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Continued fraction functions

from math import sqrt

from utils import gcd

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

def _enumerate(cf):
    """Enumerate numbers in a continued fraction, handling repeats"""
    for x in cf:
        if type(x) in [list, tuple]:
            while True:
                for y in x:
                    yield y
        yield x

def convergents(cf):
    """
    Enumerate the convergents of a continued fraction, using
    http://en.wikipedia.org/wiki/Fundamental_recurrence_formulas
    """
    
    iter = _enumerate(cf)

    b_nm1 = iter.next()
    A_nm1 = b_nm1
    B_nm1 = 1
    yield (A_nm1, B_nm1)

    b_n = iter.next()
    A_n = b_n * b_nm1 + 1
    B_n = b_n
    yield (A_n, B_n)

    while True:
        b_np1 = iter.next()
        A_np1 = b_np1*A_n + A_nm1
        B_np1 = b_np1*B_n + B_nm1
        yield (A_np1, B_np1)
        A_nm1, B_nm1, b_nm1 = A_n, B_n, b_n
        A_n, B_n, b_n = A_np1, B_np1, b_np1

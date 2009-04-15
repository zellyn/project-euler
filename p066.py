#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 66
#
# Investigate the Diophantine equation x² − Dy² = 1.

from cfrac import convergents, cf_sqrt

def pell(n):
    """
    A little reading reveals that we can use continued fraction
    convergents of the square root of n.
    http://en.wikipedia.org/wiki/Pell%27s_equation
    """

    cf = cf_sqrt(n)
    if len(cf) == 1:
        return None

    for h, k in convergents(cf):
        if h*h - n * k * k == 1:
            return (h,k)

def p066():
    hk_ds = ((pell(d), d) for d in xrange(2,1001))
    x_ds = ((hk[0], d) for (hk, d) in hk_ds if hk)
    return max(x_ds)[1]

if __name__=='__main__':
    print p066()

#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 65
#
# Find the sum of digits in the numerator of the 100th convergent of
# the continued fraction for e.

import itertools

from utils import gcd
from cfrac import cf_e

def convergent(c_frac):
    r = reversed(list(c_frac))
    n = r.next()
    d = 1

    for i in r:
        n,d = d+n*i,n
        g = gcd(n,d)
        n /= g
        d /= g

    return (n,d)

def p065():
    cf = itertools.islice(cf_e(), 100)
    n,d = convergent(cf)
    return sum((int(c) for c in str(n)))

if __name__=='__main__':
    print p065()

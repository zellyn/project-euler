#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 71
#
# Listing reduced proper fractions in ascending order of size.

from utils import gcd

def p071():
    LIMIT = 1000000

    best_diff = 1.0/35
    best_n = 0
    for d in xrange(8,LIMIT+1):
        n = d * 3 / 7
        if gcd(n,d) == 1:
            diff = 3.0/7.0 - n*1.0/d
            if diff < best_diff:
                best_diff = diff
                best_n = n

    return best_n

if __name__=='__main__':
    print p071()

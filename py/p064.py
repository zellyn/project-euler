#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 64
#
# How many continued fractions for N ≤ 10000 have an odd period?

from cfrac import cf_sqrt

def p064():
    LIMIT = 10000
    count = 0
    for i in xrange(2,LIMIT+1):
        cf = cf_sqrt(i)
        if len(cf) > 1 and len(cf[1]) % 2:
            count += 1
    return count

if __name__=='__main__':
    print p064()

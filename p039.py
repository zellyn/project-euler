#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 39
#
# If p is the perimeter of a right angle triangle, {a, b, c}, which
# value, for p ≤ 1000, has the most solutions?

import math

def p039():
    counts = {}
    for a in xrange(1,500):
        for b in xrange(a, 1000):
            c = math.sqrt(a*a+b*b)
            if math.fabs(float(c) - math.floor(c+0.5)) < 0.0001:
                p = a + b + int(math.floor(c+0.1))
                if p <= 1000:
                    counts[p] = 1 + counts.setdefault(p, 0)

    max_count = 0
    max_p = 0
    for p, count in counts.items():
        if count > max_count:
            max_count = count
            max_p = p
    return max_p

if __name__=='__main__':
    print p039()

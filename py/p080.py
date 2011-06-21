#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 80
#
# Calculating the digital sum of the decimal digits of irrational
# square roots.

# Use http://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Decimal_.28base_10.29

import math

def digitsum(n):
    digits = []
    r = 0
    c = n
    p = 0
    for count in xrange(0,100):
        x = 0
        while (20 * p + x + 1) * (x + 1) <= c:
            x += 1
        y = (20 * p + x) * x
        digits.append(x)
        p = p * 10 + x
        r = c - y
        c = r * 100
        # print "x=%d, y=%d, p=%d, r=%d, c=%d" % (x,y,p,r,c)

    return sum(digits)

def p080():
    ns = [n for n in xrange(2,100) if int(math.sqrt(n))**2 != n]
    return sum(map(digitsum, ns))

if __name__=='__main__':
    print p080()

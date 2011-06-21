#!/usr/bin/env python

# Project Euler
# Problem 9
#
# Find the only Pythagorean triplet, {a, b, c}, for which a + b + c = 1000.

from math import sqrt

def find_triple():
    for a in xrange(1,500):
        for b in xrange(a+1,500):
            c = 1000 - a - b
            if a*a+b*b==c*c:
                return (a,b,c)

def p009():
    a, b, c = find_triple()
    return a * b * c

if __name__=='__main__':
    print p009()

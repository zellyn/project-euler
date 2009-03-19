#!/usr/bin/env python

# Project Euler
# Problem 34
#
# Find the sum of all numbers which are equal to the sum of the
# factorial of their digits.

from utils import fact

P034_MAP = dict(((str(x), fact(x)) for x in xrange(0,10)))

def curiousp(n):
    return sum((P034_MAP[d] for d in str(n))) == n

def p034():
    return sum((a for a in xrange(10,2540106) if curiousp(a)))

if __name__=='__main__':
    print p034()

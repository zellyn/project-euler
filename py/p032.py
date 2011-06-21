#!/usr/bin/env python

# Project Euler
# Problem 32
#
# Find the sum of all numbers that can be written as pandigital products.

def pandigitalp(a,b):
    p = a * b
    s = "%d%d%d" % (a, b, p)
    return ''.join(sorted(s)) == "123456789"

def p032():
    prods = set()
    for a in xrange(2,99):
        for b in xrange(2,9877):
            if pandigitalp(a,b):
                prods.add(a*b)
    return sum(prods)

if __name__=='__main__':
    print p032()

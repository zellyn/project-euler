#!/usr/bin/env python

# Project Euler
# Problem 1
#
# Add all the natural numbers below one thousand that are multiples of
# 3 or 5.

def p001():
    return sum((x for x in xrange(1,1000) if (x % 3) * (x % 5) == 0))

if __name__=='__main__':
    print p001()

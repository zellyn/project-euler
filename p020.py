#!/usr/bin/env python

# Project Euler
# Problem 20
#
# Find the sum of digits in 100!

from utils import fact, digitsum

def p020():
    return digitsum(fact(100))

if __name__=='__main__':
    print p020()

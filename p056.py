#!/usr/bin/env python

# Project Euler
# Problem 56
#
# Considering natural numbers of the form, a^b, find the maximum
# digital sum.

def digitsum(n):
    return sum((int(c) for c in str(n)))

def p056():
    return max((digitsum(a**b) for a in xrange(1,100) for b in xrange(1,100)))

if __name__=='__main__':
    print p056()

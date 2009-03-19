#!/usr/bin/env python

# Project Euler
# Problem 35
#
# How many circular primes are there below one million?

from primes import is_prime, primes_less_than

def circularp(n):
    s = str(n)
    for i in xrange(1,len(s)):
        sp = int(s[i:] + s[:i])
        if not is_prime(sp):
            return False
    return True

def p035():
    return sum((1 for p in primes_less_than(1000000) if circularp(p)))

if __name__=='__main__':
    print p035()

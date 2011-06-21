#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 72
#
# How many elements would be contained in the set of reduced proper
# fractions for d ≤ 1,000,000?

from primes import primes_less_than
from p069 import totient

LIMIT = 1000000

# Too slow
def using_totient():
    """First attempt - summing the Euler totient of each number ≤ 1,000,000"""
    s = 0
    for n in xrange(LIMIT, 1, -1):
        s += totient(n)
    return s

COUNT = [0]

def sums(n, totient, i, ps, prnt=True):
    result = 0
    for j in xrange(i, len(ps)-1):
        if prnt:
            print "j=%d" % j
        p = ps[j]
        p2 = ps[j+1]
        m = p * n
        t = totient * (p-1)
        while m <= LIMIT:
            result += t
            result += sums(m, t, j+1, ps, False)
            m = p * m
            t = p * t
    return result

# Way too slow        
def using_generation():
    ps = list(primes_less_than(LIMIT+1)) + [LIMIT+1, LIMIT+2]
    return sums(1, 1, 0, ps)

# Fast!
def using_sieve():
    ps = list(primes_less_than(LIMIT+1))
    totients = [n for n in xrange(0, LIMIT+1)]
    totients[0] = totients[1] = 0

    for p in ps:
        for n in xrange(p, LIMIT+1, p):
            totients[n] = totients[n] * (p-1) / p
    return sum(totients)

def p072():
    # return using_totient()
    # return using_generation()
    return using_sieve()

if __name__=='__main__':
    #import profile
    #profile.run('p072()')
    print p072()

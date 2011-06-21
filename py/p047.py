#!/usr/bin/env python

# Project Euler
# Problem 47
#
# Find the first four consecutive integers to have four distinct
# prime factors.

import operator

from primes import prime_factors, is_prime, primes_less_than

def fast(count, limit):
    divider = reduce(operator.mul, list(primes_less_than(100))[:count-1], 1)
    
    factors = dict()
    for p in primes_less_than(limit//divider):
        for n in xrange(p, limit, p):
            factors[n] = factors.setdefault(n, 0) + 1

    candidates = set(k for k,v in factors.iteritems() if v==count)

    for c in sorted(list(candidates)):
        found = True
        for d in xrange(c+1, c+count):
            if d not in candidates:
                found = False
                break
        if found:
            return c

    return 0
    
def p047():
    return fast(4, 140000)

if __name__=='__main__':
    print p047()

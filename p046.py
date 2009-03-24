#!/usr/bin/env python

# Project Euler
# Problem 46
#
# What is the smallest odd composite that cannot be written as the sum
# of a prime and twice a square?

import math

from primes import primes_less_than

def p046():
    LIMIT = 100000
    good = set(range(9,LIMIT,2))
    squares = [2*n*n for n in xrange(1, int(math.sqrt(LIMIT//2))+1)]
    for p in primes_less_than(LIMIT):
        for s in squares:
            good.discard(p)
            good.discard(p+s)
    return list(good)[0]

if __name__=='__main__':
    print p046()

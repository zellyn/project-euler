#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 70
#
# Investigate values of n for which φ(n) is a permutation of n.

# The ratio has to be better than 87109/79180 which rules out prime
# factors < 11. Also, powers of primes dramatically break the ratio,
# so the answer must be a multiple of two primes. That's enough.

from primes import primes_less_than

def perms(n1, n2):
    return sorted(str(n1)) == sorted(str(n2))

def p070():
    winning_n = 87109
    winning_ratio = 87109.0 / 79180

    LIMIT = 10**7
    ps = list((p for p in primes_less_than(LIMIT/11) if p >= 11))
    pl = len(ps)

    for i in xrange(pl-1, 0, -1):
        x = ps[i]
        j, y, n = 0, 11, 11*x
        while n < LIMIT:
            t = (x-1) * (y-1)
            ratio = n * 1.0 / t
            if ratio < winning_ratio:
                if perms(n,t):
                    winning_n = n
                    winning_ratio = ratio
            j += 1
            y = ps[j]
            n = x * y

    return winning_n

if __name__=='__main__':
    print p070()

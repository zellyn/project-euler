#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 69
#
# Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.

# See http://en.wikipedia.org/wiki/Euler%27s_totient_function#Computing_Euler.27s_function

from primes import prime_factors, primes

def totient(n):
    factors = (factor for factor, count in prime_factors(n))
    def fact_mul(n, fact):
        return n * (fact-1) / fact
    return reduce(fact_mul, factors, n)

def max_n_lt(limit):
    max_t, max_n = 0, 0
    for n in xrange(2,limit+1):
        n_t = n*1.0/totient(n)
        if n_t > max_t:
            max_t = n_t
            max_n = n
    return max_n

def p069():
    # Playing around with max_n_lt, we see that the local maxima lie
    # at products of consecutive primes. Which makes sense, since they
    # have the most divisors.

    # 6 = 2 * 3
    # 30 = 2 * 3 * 5
    # 210 = 2 * 3 * 5 * 7
    # 2310 = 2 * 3 * 5 * 7 * 11
    # 30030 = 2 * 3 * 5 * 7 * 11 * 13
    # 510510 = 2 * 3 * 5 * 7 * 11 * 13 * 17

    LIMIT = 1000000
    result = 1
    for p in primes():
        if result * p > LIMIT:
            return result
        result *= p

if __name__=='__main__':
    print p069()

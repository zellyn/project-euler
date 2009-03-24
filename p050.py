#!/usr/bin/env python

# Project Euler
# Problem 50
#
# Which prime, below one-million, can be written as the sum of the
# most consecutive primes?

from primes import primes_less_than, is_prime

def p050():
    limit = 1000000
    ps = list(primes_less_than(limit))
    l_l = 0
    l_p = 0
    l = len(ps)
    for i in xrange(0, l-l_l+1):
        sum = 0
        plus = 0
        while sum < limit and i+plus < l-l_l+1:
            sum += ps[i+plus]
            plus += 1
            if sum < limit and is_prime(sum) and plus > l_l:
                l_l = plus
                l_p = sum
    return l_p

if __name__=='__main__':
    print p050()

#!/usr/bin/env python

# Project Euler
# Problem 12
#
# What is the value of the first triangle number to have over five
# hundred divisors?

from primes import prime_factors, is_prime

def tri(x):
    return x*(x+1)/2

def count_factors(x):
    pf = prime_factors(x)
    n = 1
    for prime, count in pf:
        n *= (count+1)
    return n

def p012():
    i = 0
    t = 0
    l = 1

    while l <= 500:
        i += 1
        t = tri(i)
        l = count_factors(t)

    return t

if __name__=='__main__':
    print p012()

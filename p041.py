#!/usr/bin/env python

# Project Euler
# Problem 41
#
# What is the largest n-digit pandigital prime that exists?

from primes import careful_is_prime

def permutations(s):
    if s:
        for i in xrange(0, len(s)):
            c = s[i]
            for m in permutations(s[:i] + s[i+1:]):
                yield c + m
    else:
        yield ''

def p041():
    m = 0
    all = "123456789"
    for i in range(2, len(all)+1):
        s = all[:i][::-1]
        for p in permutations(s):
            if careful_is_prime(int(p)):
                m = max(m, int(p))
    return m

if __name__=='__main__':
    print p041()

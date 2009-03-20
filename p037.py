#!/usr/bin/env python

# Project Euler
# Problem 37
#
# Find the sum of all eleven primes that are both truncatable from
# left to right and right to left.

from primes import primes_less_than, is_prime

def truncatable(n):
    if n < 10:
        return False
    x = n // 10
    while x:
        if not is_prime(x):
            return False
        x //= 10
    s = str(n)[1:]
    while s:
        if not is_prime(int(s)):
            return False
        s = s[1:]
    return True

def p037():
    truncs = [n for n in primes_less_than(1000000) if truncatable(n)]
    return sum(truncs)

if __name__=='__main__':
    print p037()

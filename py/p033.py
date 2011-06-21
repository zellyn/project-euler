#!/usr/bin/env python

# Project Euler
# Problem 33
#
# Discover all the fractions with an unorthodox cancelling method.

from primes import primes

def curiousp(a,b):
    if a==b: return False
    ha, la = a//10, a % 10
    hb, lb = b//10, b % 10
    if la * lb == 0: return False
    if ha == hb and a * lb == b * la: return True
    if ha == lb and a * hb == b * la: return True
    if la == hb and a * lb == b * ha: return True
    if la == lb and a * hb == b * ha: return True
    return False

def p033():
    top = 1
    bottom = 1

    for a in xrange(11, 100):
        for b in xrange(a+1, 100):
            if curiousp(a,b):
                top *= a
                bottom *= b

    for p in primes():
        if p > top:
            return bottom
        while (top % p) == (bottom % p) == 0:
            top /= p
            bottom /= p

if __name__=='__main__':
    print p033()

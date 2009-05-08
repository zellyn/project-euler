#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 87
#
# Investigating numbers that can be expressed as the sum of a prime
# square, cube, and fourth power?

import math
from primes import primes_less_than, is_prime

def p087():
    LIM = 50000000
    p4s = list(primes_less_than(int(math.pow(LIM, 1.0/4.0)+1)))
    p3s = list(primes_less_than(int(math.pow(LIM, 1.0/3.0)+1)))
    p2s = list(primes_less_than(int(math.pow(LIM, 1.0/2.0)+1)))
    results = set()
    for p4 in p4s:
        for p3 in p3s:
            for p2 in p2s:
                results.add(p4**4+p3**3+p2**2)
                # print (p2,p3,p4,p4**4+p3**3+p2**2)
    return sum(1 for r in results if r < LIM)

if __name__=='__main__':
    print p087()

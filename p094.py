#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 94
#
# Investigating almost equilateral triangles with integral sides and
# area.

# See http://en.wikipedia.org/wiki/Pythagorean_triple#Generating_a_triple
# m > n
# a = 2mn
# b = m²-n²
# c = m²+n²
# side-length = a+b+c = 2mn + m²-n² + m²+n² = 2m² + 2mn
# 2m² + 2mn < max
# 2mn < max - 2m²
# n < (max - 2m²) / 2m

# 2a = c ± 1
# 4mn + 1 = m²+n²
# 4mn - 1 = m²+n²

# 4mn = m²+n² ± 1
# 4mn - n² = m² ± 1
# n² - 4mn + m² ± 1 = 0

#              __________
#    x = -b ± √ b² - 4ac
#                 2a
#    
#    a = 1
#    b = -4m
#    c = m² ± 1
#               ________________
#    n =  4m ± √ 16m² - 4m² ± 4
#                   2
#    
#               __________
#    n =  4m ± √ 12m² ± 4
#                   2
#    
#               __________
#    n =  4m ± √ 12m² ± 4
#                   2

import math
from utils import gcd

def generate_triples(total_length_limit):
    triples = set()
    max_m = int(math.sqrt((total_length_limit)//2))
    for m in xrange(1, max_m+1):
        if m % (max_m//100) == 0:
            print "%d/%d" % (m, max_m)
        max_n = (total_length_limit - 2 * m * m) // (2 * m)
        max_n = min(max_n, m-1)
        for n in xrange(1, max_n+1):
            if not ((m+n) % 2):
                continue
            if gcd(m,n) > 1:
                continue
            b = m*m - n*n
            if b < 1:
                continue
            a = 2*m*n
            c = m*m + n*n
            a,b,c = sorted([a,b,c])
            if (a + b + c) <= total_length_limit:
                triples.add((a,b,c))
    return triples

def p094():
    return len(generate_triples(10**9))

if __name__=='__main__':
    print p094()

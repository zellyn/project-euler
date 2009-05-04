#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 75
#
# Find the number of different lengths of wire can that can form a
# right angle triangle in only one way.

# See http://en.wikipedia.org/wiki/Pythagorean_triple#Generating_a_triple
# m > n
# a = 2mn
# b = m²-n²
# c = m²+n²
# side-length = a+b+c = 2mn + m²-n² + m²+n² = 2m² + 2mn
# 2m² + 2mn < max
# 2mn < max - 2m²
# n < (max - 2m²) / 2m

import math
from utils import gcd

def generate_triples(total_length_limit):
    triples = set()
    max_m = int(math.sqrt((total_length_limit)//2))
    for m in xrange(1, max_m+1):
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
            s = a + b + c
            mult = 1
            while mult * s <= total_length_limit:
                triples.add((a*mult, b*mult, c*mult))
                mult += 1
    return triples

def p075():
    triples = generate_triples(2000000)
    length_counts = {}
    for triple in triples:
        s = sum(triple)
        length_counts[s] = length_counts.setdefault(s, 0) + 1

    return sum((lc for lc in length_counts.itervalues() if lc==1))

if __name__=='__main__':
    print p075()

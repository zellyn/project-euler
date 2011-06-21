#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 88
#
# Exploring minimal product-sum numbers for sets of different sizes.

# (* 12000 9) 2

import operator
import math
from primes import primes_less_than, primes

def increasing(min, max, max_count):
    if max_count==1:
        for x in xrange(min, max+1):
            yield (x,)
    else:
        for x in xrange(min, max+1):
            tup1 = (x,)
            yield tup1
            new_max = max//x
            for tup in increasing(x, new_max, max_count-1):
                yield tup1 + tup

def prod_n_length(tup):
    prod = reduce(operator.mul, tup)
    sum = reduce(operator.add, tup)
    length = prod - sum + len(tup)
    return (prod, length)

def p088():
    LIM = 12000
    max_sum = LIM * 2
    max_non_1s = int(math.log(max_sum, 2))
    tups = increasing(2,max_sum,max_non_1s)
    mins = {}
    for tup in tups:
        prod, length = prod_n_length(tup)
        if length > 1 and length <= LIM:
            if length not in mins or mins[length] > prod:
                mins[length] = prod
    uniques = set(mins.values())
    result = sum(uniques)
    assert result == 7587457
    return result

if __name__=='__main__':
    print p088()

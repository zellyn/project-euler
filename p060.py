#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 60
#
# Find a set of five primes for which any two primes concatenate to
# produce another prime.

import itertools
import math
from primes import primes_less_than, lazy_is_prime, is_prime, nth_prime, primes

MAX = 10000

def intlen(n):
    return int(math.log(n,10))+1

known = {}
def co_concat_prime(x, y):
    if (x,y) not in known:
        if (x % 3 + y % 3) % 3 ==0:
            known[(x,y)] = False
            return False
        mx = 10 ** intlen(x)
        my = 10 ** intlen(y)
        c1 = mx*y + x
        c2 = my*x + y
        if c1 < c2:
            known[(x,y)] = lazy_is_prime(c1) and lazy_is_prime(c2)
        else:
            known[(x,y)] = lazy_is_prime(c2) and lazy_is_prime(c1)

    return known[(x,y)]

acg_known = {}
def all_co_good(p1, p2):
    if (p1,p2) in acg_known:
        return acg_known[(p1,p2)]
    val = [p for p in primes_less_than(p2) if p>p1 and co_concat_prime(p1,p) and co_concat_prime(p,p2)]
    acg_known[(p1,p2)] = val
    return val

def tup1_gen():
    for p1 in primes():
        for p2 in primes_less_than(p1):
            if p1 != 2 and p1 != 5 and p2 != 2 and p2 != 5:
                if co_concat_prime(p2, p1):
                    yield (p2,p1)

def tup_n_prime_good(tup, pr):
    for t in tup[:-1]:
        if not co_concat_prime(t, pr):
            return False
        if not co_concat_prime(pr, tup[-1]):
            return False
    return True

def tup_gen(tups, prnt=False):
    for t in tups:
        if prnt:
            print t[-1]
        t2 = t[-2]
        for p in all_co_good(t[0], t[-1]):
            if p < t2:
                continue
            if tup_n_prime_good(t, p):
                yield t[:-1] + (p, t[-1])

def p060():
    # (13, 5197, 5701, 6733, 8389)

    is_prime(1000000)

    g = tup1_gen()
    g = tup_gen(g)
    g = tup_gen(g)
    g = tup_gen(g)
    return sum(g.next())

if __name__=='__main__':
    print p060()

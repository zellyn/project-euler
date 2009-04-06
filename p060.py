#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 60
#
# Find a set of five primes for which any two primes concatenate to
# produce another prime.

import math
from primes import primes_less_than, lazy_is_prime, is_prime

MAX = 10000

def intlen(n):
    return int(math.log(n,10))+1

known = {}
def co_concat_prime(tx, ty):
    px, mx = tx
    py, my = ty
    if (px,py) not in known:
        known[(px,py)] = lazy_is_prime(mx*py + px) and lazy_is_prime(my*px + py)
    return known[(px,py)]

def get_quad():
    is_prime(1000000)
    ps = list(primes_less_than(MAX))[1:]
    ts = [(p, 10**intlen(p)) for p in ps]
    l = len(ts)

    for e in xrange(4,l):
        te = ts[e]
        print "%s: %s" % (e, te[0])
        for d in xrange(3, e):
            td = ts[d]
            if not co_concat_prime(td,te):
                continue
            for c in xrange(2,d):
                tc = ts[c]
                if not co_concat_prime(tc,td):
                    continue
                if not co_concat_prime(tc,te):
                    continue
                for b in xrange(1,c):
                    tb = ts[b]
                    if not co_concat_prime(tb,tc):
                        continue
                    if not co_concat_prime(tb,td):
                        continue
                    if not co_concat_prime(tb,te):
                        continue
                    for a in xrange(0, b):
                        ta = ts[a]
                        if not co_concat_prime(ta,tb):
                            continue
                        if not co_concat_prime(ta,tc):
                            continue
                        if not co_concat_prime(ta,td):
                            continue
                        if not co_concat_prime(ta,te):
                            continue
                        return (ta[0],tb[0],tc[0],td[0], te[0])

def p060():
    return get_quad()

if __name__=='__main__':
    print p060()

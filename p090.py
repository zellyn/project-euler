#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 90
#
# An unexpected way of using two cubes to make a square.

targets = [(0,1), (0,4), (0,'*'), (1,'*'), (2,5), (3,'*'), (4,'*'), (8,1)]
set69 = set((6,9))


def pick(n):
    return pick_helper(n, 0, 10)

def pick_helper(n, min, max):
    if n == max-min:
        yield tuple(range(min, max))
    else:
        if n == 1:
            for k in xrange(min, max-n+1):
                yield (k,)
        else:
            for k in xrange(min, max-n+1):
                tup1 = (k,)
                for tup in pick_helper(n-1, k+1, max):
                    yield tup1 + tup

def canon_rep(die):
    s = set(die)
    if s & set69:
        s = s - set69
        s.add('*')
    return tuple(sorted(s))

def valid(d1, d2, targets):
    d1 = canon_rep(d1)
    d2 = canon_rep(d2)
    for t in targets:
        good = (t[0] in d1 and t[1] in d2) or (t[0] in d2 and t[1] in d1)
        if not good:
            return False
    return True

def p090():
    seen = set()
    choices = list(pick(6))
    for d1 in choices:
        for d2 in choices:
            if valid(d1, d2, targets):
                seen.add(tuple(sorted((d1,d2))))
    return len(seen)

if __name__=='__main__':
    print p090()

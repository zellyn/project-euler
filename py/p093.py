#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 93
#
# Using four distinct digits and the rules of arithmetic, find the
# longest sequence of target numbers.

def splits(tup):
    if len(tup)==2:
        yield ((tup[0],),(tup[1],))
    else:
        for i, t in enumerate(tup):
            rest = tup[:i] + tup[i+1:]
            for a,b in splits(rest):
                yield ((t,) + a, b)
                yield (a, (t,) + b)

def values(tup):
    if len(tup) == 1:
        yield tup[0]
    else:
        for a,b in splits(tup):
            vas = set(values(a))
            vbs = set(values(b))
            for va in vas:
                for vb in vbs:
                    yield va + vb
                    yield va - vb
                    yield va * vb
                    if vb != 0.0:
                        yield va * 1.0 / vb

def valid_values(tup):
    return set(abs(int(v)) for v in values(tup) if v and v == int(v))

def longest(tup):
    vals = sorted(valid_values(tup))
    for i,v in enumerate(vals):
        if v != i+1:
            return i
    return vals[-1]

def p093():
    max = 0
    max_digs = None
    for a in xrange(0,7):
        for b in xrange(a+1,8):
            for c in xrange(b+1,9):
                for d in xrange(c+1,10):
                    l = longest((a,b,c,d))
                    if l > max:
                        max = l
                        max_digs = (a,b,c,d)
    return reduce(lambda x,y: x*10+y, max_digs)

if __name__=='__main__':
    print p093()

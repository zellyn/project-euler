#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 74
#
# Determine the number of factorial chains that contain exactly sixty
# non-repeating terms.

from utils import fact

LIMIT = 1000000
FACTS = [fact(n) for n in xrange(0,10)]

def fact_digits(n):
    result = 0
    while n:
        result += FACTS[n%10]
        n //= 10
    return result

def p074():
    untried = set(xrange(1,LIMIT))
    lengths = {}
    while(untried):
        n = untried.pop()
        seen = []
        in_cycle = n in seen
        in_lengths = n in lengths
        while not in_cycle and not in_lengths:
            seen.append(n)
            n = fact_digits(n)
            in_cycle = n in seen
            in_lengths = n in lengths
        if in_lengths:
            ln = lengths[n]
            ls = len(seen)
            for i,n in enumerate(seen):
                lengths[n] = ln + (ls-i)
        else:
            ls = len(seen) # 5
            pos = seen.index(n) # 2
            lc = ls - pos # 3
            for i, n in enumerate(seen):
                if i < pos:
                    lengths[n] = lc + pos - i
                else:
                    lengths[n] = lc

    return sum((1 for l in lengths.itervalues() if l==60))

if __name__=='__main__':
    print p074()

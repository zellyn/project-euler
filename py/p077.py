#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 77
#
# What is the first value which can be written as the sum of primes in
# over five thousand different ways?

from primes import primes_less_than

MEMO = {}
def combos(amount, index, denoms):
    if (amount, index) not in MEMO:
        MEMO[(amount, index)] = combos2(amount, index, denoms)
    return MEMO[(amount, index)]

def combos(amount, index, denoms):
    if amount==0:
        return 1

    l = len(denoms)
    while index < l and amount < denoms[index]:
        index += 1
    if index == l-1:
        if amount % denoms[-1] == 0:
            return 1
        else:
            return 0

    if index == l:
        return 0

    d = denoms[index]
    return sum([combos(amount-d*i, index+1, denoms) for i in xrange(amount//d+1)])

def p077():
    denoms = list(reversed(list(primes_less_than(100))))

    for i in xrange(10, 100):
        count = combos(i, 0, denoms)
        if i in denoms:
            count -= 1
        if count > 5000:
            return i

if __name__=='__main__':
    print p077()

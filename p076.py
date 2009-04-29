#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 76
#
# How many different ways can one hundred be written as a sum of at
# least two positive integers?

# 50: 204226

# Try p031 approach, with memoization
MEMO = {}
def combos(amount, max):
    if (amount, max) not in MEMO:
        if max<=1:
            result = 1
        else:
            result = sum((combos(amount-max*i, max-1) for i in xrange(amount//max + 1)))
        MEMO[(amount, max)] = result
        return result
    return MEMO[(amount, max)]

def p076():
    x = 100
    return combos(x, x-1)

if __name__=='__main__':
    print p076()

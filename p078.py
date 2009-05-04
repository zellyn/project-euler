#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 78
#
# Investigating the number of ways in which coins can be separated
# into piles.

# Forums for p076 suggested looking at the partition function:
# http://mathworld.wolfram.com/PartitionFunctionP.html

# Far too slow
MEMO_p2 = {}
def p2(k, n):
    if k > n:
        return 0
    if k == n :
        return 1
    if (k,n) in MEMO_p2:
        return MEMO_p2[(k,n)]

    for i in xrange(n-1, k, -1):
        if (i,n) not in MEMO_p2:
            p2(i, n)

    result = p2(k+1, n) + p2(k, n-k)
    MEMO_p2[(k,n)] = result
    return result

# Bombs out at stack depth 1000 when amount = 1000
MEMO = {}
def combos(amount, max):
    if max > amount:
        return combos(amount, amount)

    if (amount, max) not in MEMO:
        if max<=1:
            result = 1
        else:
            result = sum([combos(amount-max*i, max-1) for i in xrange(amount//max + 1)])
        MEMO[(amount, max)] = result
        return result
    return MEMO[(amount, max)]


# Using the recurrence relation from
# http://en.wikipedia.org/wiki/Integer_partition#Generating_function

def pent(n):
    return (n * (3 * n - 1)) / 2

def gen_pent_lte(n):
    i = 1
    p = 1
    while p <= n:
        yield p
        if i < 0:
            i = -i + 1
        else:
            i = -i
        p = pent(i)

MEMO_p = {0:1, 1:1, 2:2, 3:3, 4:5}
def p(n):
    if n in MEMO_p:
        return MEMO_p[n]
    pieces = (p(n-k) for k in gen_pent_lte(n))
    result = sum((i%4<2) and p or -p for i,p in enumerate(pieces))
    MEMO_p[n] = result
    return result

def p078():
    i = 0
    while True:
        i += 1
        c = p(i)
        if c % 1000000 == 0:
            return i

if __name__=='__main__':
    print p078()

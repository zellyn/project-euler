#!/usr/bin/env python

# Project Euler
# Problem 31
#
# Investigating combinations of English currency denominations.

P031_DENOMS = [200,100,50,20,10,5,2,1]

def combos(amount, index=0):
    d = P031_DENOMS[index]
    if d<=1:
        return 1
    return sum((combos(amount-d*i, index+1) for i in xrange(amount//d+1)))

def p031():
    return combos(200)

if __name__=='__main__':
    print p031()

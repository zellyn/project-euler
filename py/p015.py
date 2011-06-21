#!/usr/bin/env python

# Project Euler
# Problem 15
#
# Starting in the top left corner in a 20 by 20 grid, how many routes
# are there to the bottom right corner?

import operator

def fact(x):
    if x<2:
        return x
    else:
        return reduce(operator.mul, xrange(2,x+1))

def p015():
    return fact(40)/(fact(20)*fact(20))

if __name__=='__main__':
    print p015()

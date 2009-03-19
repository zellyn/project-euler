#!/usr/bin/env python

# Project Euler
# Problem 28
#
# What is the sum of both diagonals in a 1001 by 1001 spiral?

def sum_spiral(n):
    steps = n//2
    num = 1
    sum = 1
    gap = 2
    for i in xrange(steps):
        for j in xrange(4):
            num += gap
            sum += num
        gap += 2
    return sum
    
def p028():
    return sum_spiral(1001)

if __name__=='__main__':
    print p028()

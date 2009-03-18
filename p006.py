#!/usr/bin/env python

# Project Euler
# Problem 6
#
# What is the difference between the sum of the squares and the square
# of the sums?

def p006():
    sum_n = sum(xrange(1,101))
    sum_n2 = sum(x*x for x in xrange(1,101))
    diff = sum_n*sum_n - sum_n2
    return diff

if __name__=='__main__':
    print p006()

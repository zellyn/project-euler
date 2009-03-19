#!/usr/bin/env python

# Project Euler
# Problem 23
#
# Find the sum of all the positive integers which cannot be written as
# the sum of two abundant numbers.

from utils import proper_divisors

def sum_of_proper_divisors(n):
    divs = proper_divisors(n)
    if divs:
        return sum(divs)
    else:
        return 1

def abundants_less_than(limit):
    return [i for i in xrange(12,limit) if sum_of_proper_divisors(i) > i]

def p023():
    include = set(xrange(1,28124))
    abundants = abundants_less_than(28124)
    for i in abundants:
        for j in abundants:
            if i <= j:
                include.discard(i+j)
    return sum(list(include))

if __name__=='__main__':
    print p023()

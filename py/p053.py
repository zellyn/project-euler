#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 53
#
# How many values of C(n,r), for 1 ≤ n ≤ 100, exceed one-million?

from utils import fact

def c(n,r):
    return (fact(n)/fact(r))/fact(n-r)

def p053():
    return sum(((c(n,r)>1000000) and 1 or 0 for n in xrange(5,101) for r in xrange(3,n+1)))

if __name__=='__main__':
    print p053()

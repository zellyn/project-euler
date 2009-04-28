#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 73
#
# How many fractions lie between 1/3 and 1/2 in a sorted set of
# reduced proper fractions?

# Use http://en.wikipedia.org/wiki/Farey_sequence#Simple_algorithm

def farey(n):
    a, b, c, d = 0, 1, 1, n
    while c < n:
        k = (n + b) // d
        a, b, c, d = c, d, k*c - a, k*d - b
        yield (a,b)

def p073():
    count = 0
    for n,d in farey(10000):
        if n * 3 <= d:
            continue
        if n * 2 >= d:
            return count
        count += 1

if __name__=='__main__':
    print p073()

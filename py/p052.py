#!/usr/bin/env python

# Project Euler
# Problem 52
#
# Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and
# 6x, contain the same digits in some order.

def good(n):
    base = sorted(str(n))
    for i in (2,3,4,5,6):
        if sorted(str(i*n)) != base:
            return False
    return True

def p052():
    i = 0
    while True:
        if str(i).startswith('1'):
            if good(i):
                return i
        i += 1

if __name__=='__main__':
    print p052()

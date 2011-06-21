#!/usr/bin/env python

# Project Euler
# Problem 4
#
# Find the largest palindrome made from the product of two 3-digit numbers.

def palindromic(n):
    s = str(n)
    return s == s[::-1]

def p004():
    return max((x*y for x in xrange(100,1000) for y in xrange(1,1000) if palindromic(x*y)))

if __name__=='__main__':
    print p004()

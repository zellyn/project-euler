#!/usr/bin/env python

# Project Euler
# Problem 16
#
# What is the sum of the digits of the number 2 ^ 1000?

def p016():
    return sum((int(c) for c in str(2**1000)))

if __name__=='__main__':
    print p016()

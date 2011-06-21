#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 97
#
# Find the last ten digits of the non-Mersenne prime: 28433 × 2**7830457 + 1.

def p097():
    return (28433 * 2**7830457 + 1) % 10**10

if __name__=='__main__':
    print p097()

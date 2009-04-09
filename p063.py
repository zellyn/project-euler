#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 63
#
# How many n-digit positive integers exist which are also an nth power?

def p063():
    count = 0
    for i in range(0,10):
        for j in range(0,21):
            if len(str(i**j))==j:
                count += 1
    return count

if __name__=='__main__':
    print p063()

#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 81
#
# Find the minimal path sum from the top left to the bottom right by
# moving right and down.

def p081():
    last = None
    for line in open('p081_matrix.txt'):
        nums = [int(i) for i in line.strip().split(',')]
        if last is None:
            last = [0] + [sys.maxint] * (len(nums)-1)
        next = [0] * len(nums)
        for i, num in enumerate(nums):
            if i==0:
                next[i] = last[i] + num
            else:
                next[i] = min(last[i], next[i-1]) + num
        last = next
    return last[-1]

if __name__=='__main__':
    print p081()

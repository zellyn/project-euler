#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 82
#
# Find the minimal path sum from the left column to the right column.

import sys

def p082():
    filename = '../data/p081_matrix.txt'
    rows = [[int(i) for i in line.strip().split(',')] for line in open(filename)]
    # rows = [[131, 673, 234, 103, 18],
    #         [201, 96, 342, 965, 150],
    #         [630, 803, 746, 422, 111],
    #         [537, 699, 497, 121, 956],
    #         [805, 732, 524, 37, 331]]
    cols = zip(*rows)
    last = cols[0]
    for col in cols[1:]:
        l = len(col)
        next = [sys.maxint] * l
        for i in xrange(0, l):
            for j in xrange(0,l):
                low = min(i,j)
                high = max(i,j)
                s = sum(col[low:high+1])
                next[low] = min(next[low], last[high] + s)
                next[high] = min(next[high], last[low] + s)
        last = next
    return min(last)

if __name__=='__main__':
    print p082()

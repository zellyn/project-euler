#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 83
#
# Find the minimal path sum from the top left to the bottom right by
# moving left, right, up, and down.

import sys

def p083():
    filename = 'p081_matrix.txt'
    rows = [[int(i) for i in line.strip().split(',')] for line in open(filename)]
    # rows = [[131, 673, 234, 103, 18],
    #         [201, 96, 342, 965, 150],
    #         [630, 803, 746, 422, 111],
    #         [537, 699, 497, 121, 956],
    #         [805, 732, 524, 37, 331]]
    # 2297

    height = len(rows)
    width = len(rows[0])
    best = [[sys.maxint] * width for x in xrange(height)]
    best[0][0] = rows[0][0]
    changed = True
    iters = 0
    while changed:
        iters += 1
        changed = False
        for y in xrange(height):
            for x in xrange(width):
                m = sys.maxint
                if y:
                    m = min(m, best[y-1][x])
                if y < height-1:
                    m = min(m, best[y+1][x])
                if x:
                    m = min(m, best[y][x-1])
                if x < width-1:
                    m = min(m, best[y][x+1])
                m = m + rows[y][x]
                if m < best[y][x]:
                    changed = True
                    best[y][x] = m
    return best[-1][-1]

if __name__=='__main__':
    print p083()

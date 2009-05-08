#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 85
#
# Investigating the number of rectangles in a rectangular grid.

# 1x1 = 1
# 2x1 = 2+1 = 3
# 3x1 = 3+2+1 = 6
# 4x1 = 4+3+2+1 = 10
# 
# 1x2 = 2 + 1 = 3
# 2x2 = 4+2 + 2+1 = 9
# 3x2 = 6+4+2 + 3+2+1 = 18
# 4x2 = 8+6+4+2 + 4+3+2+1 = 30
# 
# 1x3 = 3 + 2 + 1 = 6
# 2x3 = 6+3 + 4+2 + 2+1 = 18
# 3x3 = 9+6+3 + 6+4+2 + 3+2+1 = 36
# 4x3 = 12+9+6+3 + 8+6+4+2 + 4+3+2+1 = 60
# 
# 1x4 = 4 + 3 + 2 + 1 = 10
# 2x4 = 8+4 + 6+3 + 4+2 + 2+1 = 30
# 3x4 = 12+8+4 + 9+6+3 + 6+4+2 + 3+2+1 = 60
# 4x4 = 16+12+8+4 + 12+9+6+3 + 8+6+4+2 + 4+3+2+1 = 100

import math

def s(n):
    return n*(n+1) / 2

def rects(x,y):
    return s(x)*s(y)

def p085():
    TARGET = 2000000
    area = 0
    min_diff = TARGET

    rs = 0
    x = 100
    y = 1
    while rs < 2000000:
        x += 1
        rs = rects(x,y)
        if abs(TARGET-rs) < min_diff:
            area = x*y
            min_diff = abs(TARGET-rs)
    while y <= x:
        y += 1
        rs = TARGET + 1
        while rs>TARGET:
            x -= 1
            rs = rects(x,y)
            if abs(TARGET-rs) < min_diff:
                area = x*y
                min_diff = abs(TARGET-rs)
    return area

if __name__=='__main__':
    print p085()

#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 91
#
# Find the number of right angle triangles in the quadrant.
#
# = both points on the axis
#   q × q
# + (one point on the x axis, other point above) × 2 [no need to duplicate for y-axis, right]
#   q × q × 2
# + (one point on the diagonal, other point down + right) × 2
#   [sumto(⎣n/2⎦) + sumto(⎣(n-1)/2⎦)] × 2
# + (angled below the diagonal) × 2

from utils import gcd

def sumto(n):
    if n < 1:
        return 0
    return n * (n+1) / 2

def angled_below_diagonal(size):
    count = 0
    for x in xrange(1,size):
        for y in xrange(1,x):
            if gcd(x,y) > 1: continue
            m1 = 1
            while x*m1 <= size and y*m1 <= size:
                p1x, p1y = x*m1, y*m1
                m2 = 1
                while p1x + m2*y <= size and p1y - m2*x >= 0:
                    count += 1
                    # print ((p1x, p1y, p1x+m2*y, p1y-m2*x))
                    m2 += 1
                m2 = 1
                while p1x - m2*y >= 0 and p1y + m2*x <= size:
                    count += 1
                    # print ((p1x, p1y, p1x-m2*y, p1y+m2*x))
                    m2 += 1
                m1 += 1
    return count

def p091():
    SIZE = 50
    both_on_axis = SIZE * SIZE
    one_on_axis = SIZE * SIZE * 2
    one_on_diagonal = (sumto(SIZE//2) + sumto((SIZE-1)//2)) * 2
    angles = angled_below_diagonal(SIZE) * 2
    return both_on_axis + one_on_axis + one_on_diagonal + angles

if __name__=='__main__':
    print p091()

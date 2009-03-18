#!/usr/bin/env python

# Project Euler
# Problem 018
#
# Find the maximum sum travelling from the top of the triangle to the base.


P018_TRI = """
75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
"""

def make_tri(s):
    return [[int(n) for n in line.split()] for line in s.strip().splitlines()]

def max_path(tri):
    size = len(tri)
    sizes = {}
    for row in range(size)[::-1]:
        for col, n in enumerate(tri[row]):
            sizes[(row, col)] = n + max(sizes.get((row+1,col), 0), sizes.get((row+1,col+1), 0))
    return sizes[(0,0)]

def p018():
    return max_path(make_tri(P018_TRI))

if __name__=='__main__':
    print p018()

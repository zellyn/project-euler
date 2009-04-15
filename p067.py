#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 67
#
# Using an efficient algorithm find the maximal sum in the triangle?

from p018 import make_tri, max_path

def p067():
    f = open('p067_triangle.txt')
    text = f.read()
    f.close()
    return max_path(make_tri(text))

if __name__=='__main__':
    print p067()

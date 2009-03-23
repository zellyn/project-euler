#!/usr/bin/env python

# Project Euler
# Problem 42
#
# How many triangle words does the list of common English words contain?

from utils import read_quoted_words

def score(name):
    return sum((ord(c)-64 for c in name))

def p042():
    triangles = set((n*(n+1)/2 for n in xrange(1,1000)))
    words = read_quoted_words('p042_words.txt')
    return sum((1 for w in words if score(w) in triangles))

if __name__=='__main__':
    print p042()

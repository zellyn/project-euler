#!/usr/bin/env python

# Project Euler
# Problem 14
#
# Find the longest sequence using a starting number under one million.

P014_KNOWN = {1:1}

def seq_len(n):
    if n in P014_KNOWN:
        return P014_KNOWN[n]
    if n & 1:
        l = seq_len(3*n+1) + 1
    else:
        l = seq_len(n/2) + 1
    P014_KNOWN.setdefault(n, l)
    return l

def max_start_and_length(largest_start):
    max_len = 0
    max_n = 0
    for n in xrange(1,largest_start+1):
        l = seq_len(n)
        if l > max_len:
            max_len = l
            max_n = n
    return (max_n, max_len)

def p014():
    return max_start_and_length(999999)[0]

if __name__=='__main__':
    print p014()

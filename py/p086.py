#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 86
#
# Exploring the shortest path from one corner of a cuboid to another.

import math
from p075 import generate_triples

def cubes_lte(m, triples):
    count = 0
    for t1,t2,t3 in triples:
        if t1 <= m and t2<2*t1:
            # s3, s1+s2
            ways_of_adding_to_t2 = t2//2
            count += ways_of_adding_to_t2 - max(t2-t1-1,0)
            # print "a) %s: %d" % ((t1,t2), max(0, ways_of_adding_to_t2 - (t2-t1)))
        if t2 <= m:
            # s1+s2, s3
            count += t1//2
            # print "b) %s: %d" % ((t1,t2), t1//2)
    return count
        
def bisect(n, limit):
    triples = generate_triples(7*limit+3)
    assert cubes_lte(limit, triples) > n
    low = 1
    high = limit
    while high-low>1:
        mid = (high+low)//2
        if cubes_lte(mid, triples) > n:
            high = mid
        else:
            low = mid
    return high

def p086():
    return bisect(1000000, 2000)
if __name__=='__main__':
    print p086()

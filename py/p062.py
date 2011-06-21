#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 62
#
# Find the smallest cube for which exactly five permutations of its
# digits are cube.

def p062():
    cubes = {}
    i = 344
    digits = 3
    while True:
        i += 1
        n = i*i*i
        s = ''.join(sorted(str(n)))
        d2 = len(s)
        if d2>digits:
            ss = [ar[0] for ar in cubes.values() if len(ar)==5]
            if ss:
                return min(ss)
            digits = d2
        ar = cubes.setdefault(s,[])
        ar.append(n)

if __name__=='__main__':
    print p062()

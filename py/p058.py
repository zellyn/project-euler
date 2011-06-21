#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 58
#
# Investigate the number of primes that lie on the diagonals of the
# spiral grid.

import itertools
from primes import lazy_is_prime

def grouped_spirals():
    num = 1
    gap = 0
    yield (1,[1])
    while True:
        gap += 2
        yield (gap+1, [num+gap, num+gap*2, num+gap*3, num+gap*4])
        num = num + gap * 4

def p058():
    spiral_count = 0
    prime_count = 0
    for side_length, spirals in grouped_spirals():
        spiral_count += len(spirals)
        prime_count += sum((1 for spiral in spirals if lazy_is_prime(spiral)))

        if side_length > 2 and prime_count * 10 < spiral_count:
            return side_length

if __name__=='__main__':
    print p058()

#!/usr/bin/env python

# Project Euler
# Problem 57
#
# Investigate the expansion of the continued fraction for the square
# root of two.

#
# Looking at the first few terms, it seems we can cheat...
#

def p057():
    numerator = 3
    denominator = 2
    iter = 1

    count = 0

    while (iter < 1000):
        numerator, denominator = numerator + 2 * denominator, numerator + denominator
        iter += 1
        if len(str(numerator)) > len(str(denominator)):
            count += 1

    return count


if __name__=='__main__':
    print p057()

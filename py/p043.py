#!/usr/bin/env python

# Project Euler
# Problem 43
#
# Find the sum of all pandigital numbers with an unusual sub-string
# divisibility property.

from utils import string_permutations

def special(n):
    if n[0]=='0':
        return False
    if n[5] not in "05":
        return False
    if n[3] not in "02468":
        return False
    for p, i in ((13,6),(11,5),(7,4),(3,2)):
        if (int(n[i:i+3]) % p) != 0:
            return False
    return True

def p043():
    sum = 0
    for s in xrange(0,1000,17):
        suffix = "%03d" % s
        rest = ''.join(c for c in "0123456789" if c not in suffix)
        if len(rest)==7:
            for p in string_permutations(rest):
                num = p + suffix
                if special(num):
                    sum += int(num)
    return sum

if __name__=='__main__':
    print p043()

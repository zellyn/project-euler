#!/usr/bin/env python

# Project Euler
# Problem 49
#
# Find arithmetic sequences, made of prime terms, whose four digits
# are permutations of each other.

from primes import primes_less_than

def find_ariths(arr):
    l = len(arr)
    for i in xrange(0, l-2):
        v1 = arr[i]
        for j in xrange(i+1, l-1):
            v2 = arr[j]
            v3 = v2 + (v2-v1)
            if v3 in arr:
                yield (v1,v2,v3)

def p049():
    four_digit_primes = [p for p in primes_less_than(10000) if p > 999]
    perms = dict()
    for f in four_digit_primes:
        perms.setdefault(''.join(sorted(str(f))), []).append(f)

    candidates = [v for k, v in perms.iteritems() if len(v) > 2]

    for c in candidates:
        for ariths in find_ariths(c):
            if ariths[0] != 1487:
                return int("%d%d%d" % (ariths[0], ariths[1], ariths[2]))

if __name__=='__main__':
    print p049()

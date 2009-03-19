#!/usr/bin/env python

# Project Euler
# Problem 26
#
# Find the value of d < 1000 for which 1/d contains the longest
# recurring cycle.


# So far, this is my most lame solution!


from decimal import Decimal, getcontext
getcontext().prec = 2000

def cycle_length(f):
    ds = str(f)[2:]
    if len(ds) < 10:
        return 0
    for i in range(3,1000):
        if ds[0:i] == ds[i:i+i]:
            if ds[0] != ds[3] or ds[0] != ds[2]:
                return i
    return 0

def p026():
    max = 1
    max_r = None
    max_c = None
    one = Decimal(1)
    for d in range(11,1001,2):
        recip = one / Decimal(d)
        c = cycle_length(recip)
        if c > max:
            max = d
            max_r = recip
            max_c = c
    return max

if __name__=='__main__':
    print p026()

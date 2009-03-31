#!/usr/bin/env python

# Project Euler
# Problem 55
#
# How many Lychrel numbers are there below ten-thousand?

def lychrel(n, iters=50, first=True):
    if iters < 0:
        return True
    s = str(n)
    r = s[::-1]
    if (s==r) and not first:
        return False
    n2 = int(r)
    return lychrel(n+n2, iters-1, False)

def p055():
    return sum((1 for n in xrange(1,10000) if lychrel(n)))

if __name__=='__main__':
    print p055()

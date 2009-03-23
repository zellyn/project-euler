#!/usr/bin/env python

# Project Euler
# Problem 38
#
# What is the largest 1 to 9 pandigital that can be formed by
# multiplying a fixed number by 1, 2, 3, ... ?

def pandigital(s):
    if ''.join(sorted(s)) == '123456789':
        return int(s)
    else:
        return 0

def make_pandigital(n):
    sums = ''
    for i in xrange(1,5):
        sums += str(i * n)
        if len(sums) > 9:
            return 0
        elif len(sums) == 9:
            return pandigital(sums)


def p038():
    m = 0
    for i in xrange(1, 876):
        m = max(m, make_pandigital(int('9'+str(i))))
    return m

if __name__=='__main__':
    print p038()

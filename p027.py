#!/usr/bin/env python

# Project Euler
# Problem 27
#
# Find a quadratic formula that produces the maximum number of primes
# for consecutive values of n.

from primes import is_prime, primes

def count_primes(a,b):
    n = 0
    while True:
        if not is_prime(n*n + a*n + b):
            return n
        n += 1

def p027():
    is_prime(80*80 -79*80 + 1601)
    print "starting!"
    max = 0
    max_ab = 0

    b_primes = []
    p = primes()
    while True:
        n = p.next()
        if n < 1000:
            b_primes.append(n)
        else:
            break
    
    for a in xrange(-999,1000):
        for b in b_primes:
            count = count_primes(a,b)
            if count > max:
                max = count
                max_ab = a * b
                print "(%d, %d)" % (a,b)
    print max
    return max_ab
            

if __name__=='__main__':
    print p027()

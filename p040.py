#!/usr/bin/env python

# Project Euler
# Problem 40
#
# Finding the nth digit of the fractional part of the irrational number.

def p040():
    s = ''
    i = 1
    while len(s) <= 1000000:
        s += str(i)
        i += 1

    prod = 1
    for i in range(0,7):
        prod *= int(s[(10**i)-1])

    return prod

if __name__=='__main__':
    print p040()

#!/usr/bin/env python

# Project Euler
# Problem 2
#
# Find the sum of all the even-valued terms in the Fibonacci sequence
# which do not exceed four million.

def p002():
    fib_last = 1
    fib = 1
    total = 0

    while fib <= 4000000:
        if fib % 2 ==0:
            total += fib
        fib, fib_last = fib + fib_last, fib

    return total

if __name__=='__main__':
    print p002()

#!/usr/bin/env python

# Project Euler
# Problem 5
#
# What is the smallest number divisible by each of the numbers 1 to 20?

# Prime factors - hardly worth a program
def p005():
    return 2 * 2 * 2 * 2 * 3 * 3 * 5 * 7 * 11 * 13 * 17 * 19

if __name__=='__main__':
    print p005()

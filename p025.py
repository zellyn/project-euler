#!/usr/bin/env python

# Project Euler
# Problem 25
#
# What is the first term in the Fibonacci sequence to contain 1000 digits?

def p025():
    goal = 1000
    goal_size = 10 ** (goal-1)
    fm1 = 1
    f = 1
    n = 2
    while True:
        n += 1
        f, fm1 = f+fm1, f
        if f >= goal_size:
            return n

if __name__=='__main__':
    print p025()

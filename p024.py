#!/usr/bin/env python

# Project Euler
# Problem 24
#
# What is the millionth lexicographic permutation of the
# digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

def permutations(s):
    if len(s) == 1:
        yield s
    for i in xrange(0, len(s)):
        item = s[i]
        rest = s[:i] + s[i+1:]
        for p in permutations(rest):
            yield item + p

def p024():
    ps = permutations("0123456789")
    for i in xrange(999999):
        ps.next()
    return int(ps.next())

if __name__=='__main__':
    print p024()

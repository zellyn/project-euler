#!/usr/bin/env python

# Project Euler
# Problem 51
#
# Find the smallest prime which, by changing the same part of the
# number, can form eight different primes.

from primes import primes

def choices_with_digit(s, digit):
    pos = s.find(digit)
    if pos==-1:
        yield s
    else:
        for suffix in choices_with_digit(s[pos+1:], digit):
            yield s[:pos] + '*' + suffix
            yield s[:pos] + digit + suffix

def choices(n):
    s = str(n)
    digits = set(s[:-1])
    for d in digits:
        for c in choices_with_digit(s, d):
            if '*' in c:
                yield c

def first_with(target):
    smallest = {}
    counts = {}
    for p in primes():
        if p > 99:
            for choice in choices(p):
                if choice not in smallest:
                    smallest[choice] = p
                count = counts.setdefault(choice, 0) + 1
                counts[choice] = count
                if count == target:
                    return smallest[choice]

def p051():
    return first_with(8)
    
    return list(choices('1223'))

if __name__=='__main__':
    print p051()

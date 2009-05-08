#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 89
#
# Develop a method to express Roman numerals in minimal form.

import itertools
import re

LETTER_VALUES = dict(I=1, V=5, X=10, L=50, C=100, D=500, M=1000)
GROUP_RE = re.compile('([IVXLCD]M|[IVXLC]D|[IVXL]C|[IVX]L|[IV]X|IV|[IVXLCDM])')
GROUPS = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']

def group_value(s):
    if len(s)==1: return LETTER_VALUES[s]
    return LETTER_VALUES[s[1]] - LETTER_VALUES[s[0]]

def to_roman(n):
    result = ''
    groups = GROUPS[::-1]
    while n:
        group = groups.pop()
        value = group_value(group)
        while value <= n:
            n -= value
            result += group
    return result

def from_roman(r):
    return sum(map(group_value, GROUP_RE.findall(r)))

def p089():
    total = 0
    for line in open('p089_roman.txt'):
        roman_in = line.strip()
        roman_out = to_roman(from_roman(roman_in))
        total += len(roman_in) - len(roman_out)
    return total

if __name__=='__main__':
    print p089()

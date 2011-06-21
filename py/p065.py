#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 65
#
# Find the sum of digits in the numerator of the 100th convergent of
# the continued fraction for e.

import itertools

from utils import gcd
from cfrac import cf_e, convergents

def p065():
    n,d = itertools.islice(convergents(cf_e()), 99, 100).next()
    return sum((int(c) for c in str(n)))

if __name__=='__main__':
    print p065()

#!/usr/bin/env python

# Project Euler
# Harness: display results and times

import time

n_probs = 18
fs = []
for n in range(1,n_probs+1):
    pname = "p%03d" % n
    mod = __import__(pname, globals(), locals())
    fs.append(mod.__dict__[pname])

print
for i in range(1,n_probs+1)[::-1]:
    print "p%03d:" % i,
    before = time.time()
    value = fs[i-1]()
    after = time.time()
    diff = after - before
    print "% 20d - % 1f" % (value, diff)

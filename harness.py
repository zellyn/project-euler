#!/usr/bin/env python

# Project Euler
# Harness: display results and times

import time

answers = [
    233168, 4613732, 6857, 906609, 232792560, 25164150, 104743, 40824, 31875000, 142913828922,
    70600674, 76576500, 5537376230, 837799, 137846528820, 1366, 21124, 1074, 171, 648,
    31626, 871198282, 4179871, 2783915460, 4782, 983, -59231, 669171001, 9183, 443839,
    73682, 45228, 100, 40730, 55, 872187, 748317, 932718654, 840, 210,
    7652413, 162, 16695334890, 5482660, 1533776805
]

n_probs = len(answers)
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
    answer = answers[i-1]
    assert value==answer, "The answer to problem %d should be %d, not %d" % (i, answer, value)
    print "% 20d - % 1f" % (value, diff)

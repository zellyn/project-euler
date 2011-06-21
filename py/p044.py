#!/usr/bin/env python

# Project Euler
# Problem 44
#
# Find the smallest pair of pentagonal numbers whose sum and
# difference is pentagonal.
#
# Lucky!

def p044():
    LIMIT = 2200
    pents = [n*(3*n-1)/2 for n in xrange(1,LIMIT*2)]
    assert pents[LIMIT]*2 < pents[-1], "%d < %d" % (pents[LIMIT]*2, pents[-1])
    pents_s = set(pents)
    diffs = []
    for i in xrange(0,LIMIT):
        p1 = pents[i]
        for j in xrange(i, LIMIT):
            p2 = pents[j]
            if (p2-p1) in pents_s and (p2+p1) in pents_s:
                diffs.append((p1,p2))
    return diffs[0][1] - diffs[0][0]

if __name__=='__main__':
    print p044()

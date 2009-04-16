#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 68
#
# What is the maximum 16-digit string for a "magic" 5-gon ring?

#       1._       3             1
#         _.0._  /                \
#     _.8'     `2                  0
#   9'   \     /                 /   \
#         6---4---5             4-----2-----3
#          \                  /
#           7                5

SIZE = 10
NUMBERS = set(range(1,SIZE+1))

def initial():
    if SIZE == 10:
        for a in xrange(1,10):
            for b in xrange(1,10):
                if a != b:
                    yield ((a,10,b), a+10+b)
    elif SIZE == 6:
        for a in xrange(1,7):
            for b in xrange(1,7):
                if a != b:
                    for c in xrange(1,7):
                        if c != a and c != b:
                            yield ((a,b,c), a+b+c)

def find_all_from(start):
    if start is None:
        gen = initial()
    else:
        gen = gen_func(start)

    for g in gen:
        if len(g[0])==SIZE:
            yield g[0]
        else:
            for d in find_all_from(g):
                yield d

def gen_func(fg_s):
    fg, s = fg_s
    available = NUMBERS - set(fg)
    last = fg[-1]
    if len(available) > 3:
        for x in available:
            y = s - last - x
            if y != x and y in available:
                yield (fg+(x,y), s)
    else:
        first = fg[0]
        for x in available:
            y = s - last - x
            z = s - first - y
            if y in available and z in available and y != x and y != z and x != z:
                yield (fg + (x,y,z), s)
                
    
def outers(fg):
    return fg[1::2]

def inners(fg):
    return fg[::2]

def triples(fg):
    return [(fg[i+1],fg[i],fg[(i+2)%SIZE]) for i in xrange(0, SIZE, 2)]

def score(fg):
    ts = triples(fg)
    min_pos = min((t[0], i) for i,t in enumerate(ts))[1]
    ts = ts[min_pos:] + ts[:min_pos]
    return int(''.join([str(n) for t in ts for n in t]))

def p068():
    return max([score(x) for x in find_all_from(None)])

if __name__=='__main__':
    print p068()

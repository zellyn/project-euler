#!/usr/bin/env python

# Project Euler
# Problem 45
#
# After 40755, what is the next triangle number that is also
# pentagonal and hexagonal?

def common(g1, g2):
    v1 = g1.next()
    v2 = g2.next()
    while True:
        if v1 == v2:
            yield v1
            v1 = g1.next()
            v2 = g2.next()
        elif v1 < v2:
            v1 = g1.next()
        else:
            v2 = g2.next()

def tris():
    i = 1
    while True:
        yield i*(i+1)/2
        i += 1

def pents():
    i = 1
    while True:
        yield i*(3*i-1)/2
        i += 1

def hexes():
    i = 1
    while True:
        yield i*(2*i-1)
        i += 1
    
def p045():
    g = common(common(tris(), pents()), hexes())
    return g.next()


if __name__=='__main__':
    print p045()

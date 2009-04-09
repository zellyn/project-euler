#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 61
#
# Find the sum of the only set of six 4-digit figurate numbers with a
# cyclic property.

def pgonal(p,n):
    return n * ((p-2)*n + 4-p) / 2

def fits(so_far, n):
    if n // 100 != so_far[-1] % 100:
        return False
    if len(so_far) < 5:
        return True
    return n % 100 == so_far[0] // 100

def gen(state):
    if state is None:
        unused = [pgonal_4_digits(p) for p in (3,4,5,6,7)]
        eights = pgonal_4_digits(8)
        return [((n,), unused) for n in eights]

    so_far, unused = state
    ret_val = []
    for i, u in enumerate(unused):
        next_unused = unused[:i] + unused[i+1:]
        for n in u:
            if fits(so_far, n):
                ret_val.append((so_far+(n,), next_unused))
    return ret_val

def success(state):
    return len(state[0])==6
        
def search(success_func, gen_func, breadth_first=True):
    stack = [None]
    while stack:
        top = stack.pop()
        succs = gen_func(top)
        for s in succs:
            if success_func(s):
                return s
        if breadth_first:
            stack = stack + succs
        else:
            stack = succs + stack
    return None
    
def pgonal_4_digits(p):
    result = []
    i = 0
    while True:
        i += 1
        n = pgonal(p, i)
        if n > 9999:
            return result
        if n > 999:
            result.append(n)

def p061():
    picks = [pgonal_4_digits(p) for p in (3,4,5,6,7,8)]
    success_state = search(success, gen)
    return sum(success_state[0])

if __name__=='__main__':
    print p061()

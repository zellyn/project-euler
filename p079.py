#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 79
#
# By analysing a user's login attempts, can you determine the secret
# numeric passcode?

# Accidentally figured it out while working the first few tries by hand!
# 73162890

def passes(password, key):
    a,b,c = key
    return a in password and b in password and b in password[password.find(a)+1:password.rfind(c)]

def inserts(password, key):
    yield password
    a,b,c = key
    l = len(password)+1
    for i in xrange(0,l):
        p0i = password[:i]
        pi0 = password[i:]
        yield p0i + a + pi0
        yield p0i + b + pi0
        yield p0i + c + pi0
        for j in xrange(i, l):
            pij = password[i:j]
            pj0 = password[j:]
            yield p0i + a + pij + b + pj0
            yield p0i + a + pij + c + pj0
            yield p0i + b + pij + c + pj0
            for k in xrange(j, l):
                pjk = password[j:k]
                pk0 = password[k:]
                yield p0i + a + pij + b + pjk + c + pk0

def p079():
    BUFFER = 1
    codes = ['']
    keys = [l.strip() for l in open('p079_keylog.txt')]
    keys = sorted(set(keys))

    for index, key in enumerate(keys):
        # print '%d/%d: %s (%d)' % (index+1, len(keys), key, len(codes))
        new_codes = set()
        for code in codes:
            for i in inserts(code, key):
                if passes(i, key):
                    new_codes.add(i)
        min_len = min(len(c) for c in new_codes)
        codes = [c for c in new_codes if len(c) <= min_len+BUFFER]

    return int(sorted(codes, key=len)[0])

if __name__=='__main__':
    print p079()

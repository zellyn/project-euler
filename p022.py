#!/usr/bin/env python

# Project Euler
# Problem 22
#
# What is the total of all the name scores in the file of first names?

def read_names():
    f = None
    try:
        f = open("p022_names.txt", "r")
        data = f.read().strip()
        q_names = data.split(",")
        names = [q_name[1:-1] for q_name in q_names]
        return names
    finally:
        if f: f.close()

def score(name):
    return sum((ord(c)-64 for c in name))

def p022():
    names = read_names()
    names.sort()
    scores = [(i+1) * score(name) for i, name in enumerate(names)]
    return sum(scores)

if __name__=='__main__':
    print p022()

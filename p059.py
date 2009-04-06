#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 59
#
# Using a brute force attack, can you decrypt the cipher using XOR encryption?

# From http://www.cs.chalmers.se/Cs/Grundutb/Kurser/krypto/en_stat.html
SAMPLE_TRIGRAMS = [tuple([ord(c) for c in w]) for w in [' th', 'he ',
'the', 'ed ', 'nd ', ' an', 'and', ' to', 'ng ', ' he', 'er ',
'ing', 'to ', ' of', 'at ', 'of ', 'is ', 'd t', ' in', ' hi',
' ha', 'e t', 'as ', 'her', 'in ',]]

def read_bytes():
    f = None
    try:
        f = open("p059_cipher1.txt", "r")
        data = f.read().strip()
        str_bytes = data.split(",")
        bytes = [int(s_b) for s_b in str_bytes]
        return bytes
    finally:
        if f: f.close()

def offset_trigrams(text):
    """Return trigrams at position 3n, 3n+1, 3n+2"""
    return (((text[i], text[i+1], text[i+2]) for i in xrange(j, len(text)-2, 3)) for j in (0,1,2))

def offset_trigram_counts(text):
    """Return counts of trigrams at position 3n, 3n+1, 3n+2"""
    return map(trigram_counts, offset_trigrams(text))

def trigram_counts(trigrams):
    """Given a stream of trigrams, return a dict of trigram counts"""
    counts = {}
    for t in trigrams:
        counts[t] = 1 + counts.setdefault(t, 0)
    return counts

def xor_text(text, key):
    """Xor a long text with a key"""
    return [b ^ key[i%3] for i,b in enumerate(text)]

def xor(t, key):
    """Xor a triple with a key"""
    return (t[0]^key[0], t[1]^key[1], t[2]^key[2])

def score(otc, key):
    """
    Given counts of trigrams at position 3n, 3n+1, 3n+2, and a proposed key,
    return a score of how often the common English trigrams show up.
    """
    offset_keys = [key, key[1:]+key[:1], key[2:]+key[:2]]
    s = 0
    for offset_counts, k in zip(otc, offset_keys):
        for t in SAMPLE_TRIGRAMS:
            s += offset_counts.get(xor(t, k), 0)
    return s

def p059():
    text = read_bytes()
    otc = offset_trigram_counts(text)

    guesses = ((x,y,z)
               for x in xrange(97, 123)
               for y in xrange(97, 123)
               for z in xrange(97, 123))

    best = max(((score(otc, guess), guess) for guess in guesses))[1]
    new_text = xor_text(text, best)
    return sum(new_text)

if __name__=='__main__':
    print p059()

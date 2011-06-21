#!/usr/bin/env python

# Project Euler
# Problem 17
#
# How many letters would be needed to write all the numbers in words
# from 1 to 1000?

words_nn = [
    'zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven',
    'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen',
    'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen',
    ]
words_tens = [
    'zero', 'ten', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty',
    'ninety',
    ]

def english(n):
    if n < 20:
        return words_nn[n]
    if n < 100:
        tens = words_tens[n//10]
        rem = n % 10
        if rem:
            return "%s-%s" % (tens, english(rem))
        else:
            return tens

    if n < 1000:
        hundreds = "%s hundred" % english(n//100)
        if n % 100 == 0:
            return hundreds
        else:
            return "%s and %s" % (hundreds, english(n % 100))

    if n == 1000:
        return "one thousand"
    raise Exception("n>1000 not yet implemented")

def charlen(s):
    return sum((1 for c in s if c not in ' -'))

def p017():
    return sum(charlen(english(n)) for n in xrange(1,1001))

if __name__=='__main__':
    print p017()

# Miscellaneous utility routines

import operator

from primes import prime_factors

def fact(x):
    if x<2:
        return 1
    else:
        return reduce(operator.mul, xrange(2,x+1))

def digitsum(x):
    return sum((int(c) for c in str(x)))

def divisors_from_factorization(pairs):
    if not pairs:
        yield 1
    else:
        prime, max = pairs[0]
        sub_factors = divisors_from_factorization(pairs[1:])
        for sub_factor in sub_factors:
            for count in xrange(0, max+1):
                yield (prime ** count) * sub_factor

def divisors(n):
    
    pf = prime_factors(n)
    divisors = divisors_from_factorization(pf)
    return list(divisors)

def proper_divisors(n):
    return divisors(n)[:-1]

def read_quoted_words(filename):
    f = None
    try:
        f = open(filename, "r")
        data = f.read().strip()
        q_names = data.split(",")
        names = [q_name[1:-1] for q_name in q_names]
        return names
    finally:
        if f: f.close()

def string_permutations(st):
    if st:
        for i in xrange(0, len(st)):
            c = st[i]
            for m in string_permutations(st[:i] + st[i+1:]):
                yield c + m
    else:
        yield ''

def all_pandigitals_as_strings():

    all = "123456789"
    for i in range(1, len(all)+1):
        s = all[:i][::-1]
        for p in string_permutations(s):
            yield(p)

def gcd(x,y):
    if x<y:
        return gcd(y,x)

    r = x%y
    if r==0:
        return y

    return gcd(y,r)

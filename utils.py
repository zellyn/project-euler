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

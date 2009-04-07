# Miscellaneous prime-related routines
#
# I expect I'll need to improve these as the problems get more complex

import math

_primes = [2,3,5]
_primes_set = set(_primes)
_last_try = [5]
_inc = [2]

def fill(limit):
    new_primes = set()
    last_try = _last_try[0]
    inc = _inc[0]
    while last_try < limit:
        prime = False
        while not prime:
            last_try += inc
            inc = 6 - inc
            if last_try == 5:
                print "last_try==%d" % last_try
            prime = True
            for p in _primes:
                if p*p > last_try:
                    break
                if last_try % p == 0:
                    prime = False
                    break
        if prime:
            _primes.append(last_try)
            new_primes.add(last_try)
    _primes_set.update(new_primes)
    _last_try[0] = last_try
    _inc[0] = inc

def primes():
    i = -1
    while True:
        i += 1
        if i >= len(_primes):
            fill(_primes[-1]+100000)
        yield _primes[i]

def primes_less_than(n):
    is_prime(n)
    g = primes()
    p = g.next()
    while p < n:
        yield p
        p = g.next()

def lazy_is_prime(n):
    if n < 100000 or n < _last_try[0]:
        return is_prime(n)
    
    s = math.sqrt(n+1)
    if s >= _last_try[0]:
        fill(s+10000)

    for p in _primes:
        if p*p > n:
            return True
        if n % p == 0:
            return False
    return True

def nth_prime(n):
    while len(_primes) < n:
        fill(_last_try[0]+100000)
    return _primes[n-1]

def is_prime(n):
    if n < 2:
        return False
    if n > _last_try[0]:
        fill(n+100000)
    return n in _primes_set

def careful_is_prime(n):
    return lazy_is_prime(n)

def prime_factors(n):
    factors = []
    for p in primes():
        if p>n:
            return factors
        count = 0
        while n % p == 0:
            n = n / p
            count += 1
        if count:
            factors.append((p, count))
    return factors

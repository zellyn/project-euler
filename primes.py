# Miscellaneous prime-related routines
#
# I expect I'll need to improve these as the problems get more complex

import math

_primes = [2,3]
_primes_set = set(_primes)
_last_try = [3]

def fill(limit):
    new_primes = set()
    last_try = _last_try[0]
    while last_try < limit:
        prime = False
        while not prime:
            last_try += 2
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

def primes():
    i = -1
    while True:
        i += 1
        if i >= len(_primes):
            fill(_primes[-1]*2)
        yield _primes[i]

def primes_less_than(n):
    is_prime(n)
    g = primes()
    p = g.next()
    while p < n:
        yield p
        p = g.next()

def lazy_is_prime(n):
    if n < 100000:
        return is_prime(n)
    
    s = math.sqrt(n+1)
    if s >= _last_try[0]:
        fill(s+10000)

    return careful_is_prime(n)
    
def is_prime(n):
    if n < 2:
        return False
    if n > _last_try[0]:
        fill(n+100000)
    return n in _primes_set

def careful_is_prime(n):
    if n < _last_try[0]:
        return is_prime(n)
    for p in primes_less_than(math.sqrt(n)+1):
        if n % p == 0:
            return False
    return True

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

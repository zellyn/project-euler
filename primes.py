# Miscellaneous prime-related routines
#
# I expect I'll need to improve these as the problems get more complex

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

def is_prime(n):
    if n < 2:
        return False
    if n > _last_try[0]:
        fill(n+1)
    return n in _primes_set

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

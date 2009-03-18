_primes = [2,3]
_last_primee = 3

def fill(limit):
    _last_primee = _primes[-1]
    
    while _last_primee < limit:
        prime = False
        while not prime:
            _last_primee += 2
            if _last_primee >= limit:
                break
            prime = True
            for p in _primes:
                if p*p > _last_primee:
                    break
                if _last_primee % p == 0:
                    prime = False
                    break
        if prime:
            _primes.append(_last_primee)

def primes():
    i = -1
    while True:
        i += 1
        if i >= len(_primes):
            fill(_primes[-1]*2)
        yield _primes[i]

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

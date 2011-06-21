#!/usr/bin/env python

# Project Euler
# Problem 10
#
# Calculate the sum of all the primes below two million.

def p010():
    last_prime = 3
    primes = [2, 3]

    while last_prime < 2000000:
        prime = False
        while not prime:
            last_prime += 2
            if last_prime >= 2000000:
                break
            prime = True
            for p in primes:
                if p*p > last_prime:
                    break
                if last_prime % p == 0:
                    prime = False
                    break
        if prime:
            primes.append(last_prime)

    return sum((prime for prime in primes if prime < 2000000))

if __name__=='__main__':
    print p010()

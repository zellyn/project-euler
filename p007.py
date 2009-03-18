#!/usr/bin/env python

# Project Euler
# Problem 7
#
# Find the 10001st prime.

def p007():
    last_prime = 3
    primes = [2, 3]

    while len(primes) < 10001:
        prime = False
        while not prime:
            last_prime += 2
            prime = True
            for p in primes:
                if last_prime % p == 0:
                    prime = False
                    break
        primes.append(last_prime)

    return primes[10000]

if __name__=='__main__':
    print p007()

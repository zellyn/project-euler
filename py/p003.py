#!/usr/bin/env python

# Project Euler
# Problem 3
#
# Find the largest prime factor of a composite number.

def p003():
    num = 600851475143
    last_prime = 3
    primes = [2, 3]
    largest = 0

    while num > 1:
        if num % last_prime == 0:
            largest = last_prime
            num = num / last_prime
        else:
            prime = False
            while not prime:
                last_prime += 2
                prime = True
                for p in primes:
                    if last_prime % p == 0:
                        prime = False
                        break

    return largest

if __name__=='__main__':
    print p003()

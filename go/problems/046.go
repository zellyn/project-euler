// Project Euler Problem 046
//
// What is the smallest odd composite that cannot be written as the
// sum of a prime and twice a square?

package problems

import (
	"fmt"

	"../primes"
)

func isGoldbachException(n int) bool {
	if primes.IsPrime(n) {
		return false
	}
	for i2, inc := 0, 2; i2 < n; i2, inc = i2+inc, inc+4 {
		if primes.IsPrime(n - i2) {
			return false
		}
	}
	return true
}

func Problem046() string {
	for n := 37; ; n += 2 {
		if isGoldbachException(n) {
			return fmt.Sprint(n)
		}
	}
	panic("unreachable")
}

func init() {
	Functions[46] = Problem046
}

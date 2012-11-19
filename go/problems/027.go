// Project Euler Problem 027
//
// Find a quadratic formula that produces the maximum number of primes
// for consecutive values of n.

package problems

import (
	"fmt"

	"../primes"
)

func PrimesFor(a, b int) int {
	for n := 0; ; n++ {
		if !primes.IsPrime(n*n + a*n + b) {
			return n
		}
	}
	panic("Not reached")
}

func Problem027() string {
	nmax, prodmax := 0, 0
	for b := 0; b < 1000; b++ {
		// Can't be negative; figure out min a for n=3
		for a := (-b - 9) / 3; a < 1000; a++ {
			if n := PrimesFor(a, b); n > nmax {
				nmax = n
				prodmax = a * b
			}
		}
	}
	return fmt.Sprintf("%d", prodmax)
}

func init() {
	Functions[27] = Problem027
}

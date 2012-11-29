// Project Euler Problem 058
//
// Investigate the number of primes that lie on the diagonals of the
// spiral grid.

package problems

import (
	"fmt"

	"../primes"
)

func Problem058() string {
	last, length, prime, total := 9, 3, 3, 5
	for prime*10 > total {
		length += 2
		for i := 0; i < 4; i++ {
			last += length - 1
			total++
			if primes.IsPrime(last) {
				prime++
			}
		}
	}
	return fmt.Sprint(length)
}

func init() {
	Functions[58] = Problem058
}

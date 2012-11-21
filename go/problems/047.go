// Project Euler Problem 047
//
// Find the first four consecutive integers to have four distinct
// primes factors.

package problems

import (
	"fmt"

	"../primes"
)

func Problem047() string {
	found := 0
	for i := 10; ; i++ {
		if len(primes.PrimeFactors(i)) == 4 {
			found++
			if found == 4 {
				return fmt.Sprint(i + 1 - 4)
			}
		} else {
			found = 0
		}
	}
	panic("unreachable")
}

func init() {
	Functions[47] = Problem047
}

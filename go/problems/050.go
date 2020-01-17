// Project Euler Problem 050
//
// Which prime, below one-million, can be written as the sum of the
// most consecutive primes?

package problems

import (
	"fmt"

	"github.com/zellyn/project-euler/go/primes"
)

func Problem050() string {
	sums := []int{}
	sum := 0
	for n := 0; ; n++ {
		if p := primes.Get(n); p < 1000000 {
			sum += p
			sums = append(sums, sum)
		} else {
			break
		}
	}
	longest := 0
	prime := 0
	for i := 0; i < len(sums)-1; i++ {
		for j := i + 1 + longest; j < len(sums); j++ {
			sum := sums[j] - sums[i]
			if sum >= 1000000 {
				break
			}
			if primes.IsPrime(sum) {
				longest = j - i
				prime = sum
			}
		}
	}
	return fmt.Sprint(prime)
}

func init() {
	Functions[50] = Problem050
}

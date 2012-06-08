// Project Euler Problem 005
//
// What is the smallest number divisible by each of the numbers 1 to 20?

package problems

import (
	"fmt"

	"../primes"
)

func Problem005() string {
	var total int64 = 1
	counts := make(map[int64]int)
	for i := 2; i <= 20; i++ {
		for _, factor := range primes.PrimeFactors(int64(i)) {
			for factor.Count > counts[factor.Prime] {
				total *= factor.Prime
				counts[factor.Prime]++
			}
		}
	}
	return fmt.Sprint(total)
}

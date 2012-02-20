// Project Euler Problem 005
//
// What is the smallest number divisible by each of the numbers 1 to 20?

package main

import (
	"fmt"

	"./primes"
)

func main() {
	var total int64 = 1
	counts := make(map[int64]int)
	for i := 2; i <= 20; i++ {
		var last int64 = 0
		count := 0
		for _, factor := range primes.PrimeFactors(int64(i)) {
			if factor == last {
				count++
			} else {
				last = factor
				count = 1
			}
			if counts[factor] < count {
				counts[factor] = count
				total *= factor
			}
		}
	}
	fmt.Println(total)
}

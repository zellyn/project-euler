// Project Euler Problem 012
//
// What is the value of the first triangle number to have over five
// hundred divisors?

package main

import (
	"fmt"

	"./primes"
)

func main() {
	var n, tri int64 = 1, 0
	for ; ; n, tri = n+1, tri+n {
		count := 1
		for _, factor := range primes.PrimeFactors(tri) {
			count *= (factor.Count + 1)
		}
		if count > 500 {
			fmt.Println(tri)
			return
		}
	}
}

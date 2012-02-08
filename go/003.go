// Project Euler Problem 003
//
// Find the largest prime factor of a composite number.

package main

import (
	"fmt"

	"./primes"
)

func main() {
	var product int64 = 600851475143
	factors := primes.PrimeFactors(product)
	fmt.Println(factors[len(factors)-1])
}

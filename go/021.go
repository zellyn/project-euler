// Project Euler Problem 021
//
// Evaluate the sum of all amicable pairs under 10000.

package main

import (
	"fmt"

	"./primes"
)

func main() {
	sum := int64(0)
	for i := int64(2); i < 10000; i++ {
		sd := primes.SumDivisors(i)
		if sd > i && primes.SumDivisors(sd) == i {
			sum += i + sd
		}
	}
	fmt.Println(sum)
}

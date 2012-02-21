// Project Euler Problem 010
//
// Calculate the sum of all the primes below two million.

package main

import (
	"fmt"

	"./primes"
)

func main() {
	var sum int64 = 0
	i := 0
	for {
		p := primes.Get(i)
		i++
		if p >= 2000000 {
			break
		}
		sum += p
	}
	fmt.Println(sum)
}

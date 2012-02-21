// Project Euler Problem 007
//
// Find the 10001st prime.

package main

import (
	"fmt"

	"./primes"
)

func main() {
	fmt.Println(primes.Get(10000))
}

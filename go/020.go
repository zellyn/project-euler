// Project Euler Problem 020
//
// Find the sum of digits in 100!

package main

import (
	"big"
	"fmt"
)

func main() {
	s := big.NewInt(1).MulRange(2, 100).String()
	sum := 0
	for _, c := range s {
		sum += c - '0'
	}
	fmt.Println(sum)
}

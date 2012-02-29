// Project Euler Problem 016
//
// What is the sum of the digits of the number 2^1000?

package main

import (
	"big"
	"fmt"
)

func main() {
	num := big.NewInt(0).Exp(big.NewInt(2), big.NewInt(1000), nil)
	s := num.String()
	sum := 0
	for _, c := range s {
		sum += c - '0'
	}
	fmt.Println(sum)
}

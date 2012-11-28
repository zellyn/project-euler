// Project Euler Problem 056
//
// Considering natural numbers of the form, a^b, where a, b < 100,
// what is the maximum digital sum?

package problems

import (
	"fmt"
	"math/big"
)

func bigDigitSum(n *big.Int) int {
	sum := 0
	for _, c := range n.String() {
		sum += int(c - '0')
	}
	return sum
}

func Problem056() string {
	max := 0
	for a := int64(2); a < 100; a++ {
		bigA := big.NewInt(a)
		for b := int64(2); b < 100; b++ {
			bigB := big.NewInt(b)
			z := big.NewInt(0)
			z.Exp(bigA, bigB, nil)
			sum := bigDigitSum(z)
			if sum > max {
				max = sum
			}
		}
	}
	return fmt.Sprint(max)
}

func init() {
	Functions[56] = Problem056
}

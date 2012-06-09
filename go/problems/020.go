// Project Euler Problem 020
//
// Find the sum of digits in 100!

package problems

import (
	"fmt"
	"math/big"
)

func Problem020() string {
	s := big.NewInt(1).MulRange(2, 100).String()
	sum := 0
	for _, c := range s {
		sum += int(c - '0')
	}
	return fmt.Sprint(sum)
}

func init() {
     Functions[20] = Problem020
}

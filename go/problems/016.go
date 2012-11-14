// Project Euler Problem 016
//
// What is the sum of the digits of the number 2^1000?

package problems

import (
	"fmt"
	"math/big"
)

func Problem016() string {
	num := big.NewInt(0).Exp(big.NewInt(2), big.NewInt(1000), nil)
	s := num.String()
	sum := 0
	for _, c := range s {
		sum += int(c - '0')
	}
	return fmt.Sprint(sum)
}

func init() {
	Functions[16] = Problem016
}

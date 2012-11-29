// Project Euler Problem 057
//
// Investigate the expansion of the continued fraction for the square
// root of two.

package problems

import (
	"fmt"
	"math/big"
)

func Problem057() string {
	count := 0
	numerator, denominator, tmp := big.NewInt(3), big.NewInt(2), big.NewInt(0)
	for i := 0; i < 1000; i++ {
		tmp.Set(numerator)
		numerator.Add(numerator, denominator)
		numerator.Add(numerator, denominator)
		denominator.Add(denominator, tmp)
		if len(numerator.String()) > len(denominator.String()) {
			count++
		}
	}
	return fmt.Sprint(count)
}

func init() {
	Functions[57] = Problem057
}

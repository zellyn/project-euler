// Project Euler Problem 065
//
// Find the sum of digits in the numerator of the 100th convergent of
// the continued fraction for e.

package problems

import (
	"fmt"
	"math/big"

	"github.com/zellyn/project-euler/go/contfrac"
)

func bigDigitCount(n *big.Int) (count int) {
	for _, c := range n.String() {
		count += int(c - '0')
	}
	return count
}

func Problem065() string {
	c := contfrac.Convergents(contfrac.E())
	var d *big.Int
	for i := 0; i < 100; i++ {
		is := <-c
		d = is[0]
	}
	return fmt.Sprint(bigDigitCount(d))
}

func init() {
	Functions[65] = Problem065
}

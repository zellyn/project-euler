// Project Euler Problem 025
//
// What is the first term in the Fibonacci sequence to contain 1000
// digits?

package problems

import (
	"fmt"
	"math/big"
)

func Problem025() string {
	f1, f2 := big.NewInt(1), big.NewInt(1)
	var i int
	for i = 2; len(f2.String()) < 1000; i++ {
		f1.Add(f1, f2)
		f2, f1 = f1, f2
	}
	return fmt.Sprintf("%d", i)
}

func init() {
	Functions[25] = Problem025
}

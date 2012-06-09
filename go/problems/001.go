// Project Euler Problem 001
//
// Add all the natural numbers below one thousand that are multiples
// of 3 or 5.

package problems

import "fmt"

func Problem001() string {
	total := 0
	for i := 0; i < 1000; i++ {
		if (i%3)*(i%5) == 0 {
			total += i
		}
	}
	return fmt.Sprintf("%d", total)
}

func init() {
     Functions[1] = Problem001
}

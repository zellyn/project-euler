// Project Euler Problem 015
//
// Starting in the top left corner in a 20 by 20 grid, how many routes
// are there to the bottom right corner?

// 40 choose 20 = 40! / 20! / 20!
// 40! / 20! / 20!  - 20! drops out 20 and below from numerator
// = 40*39*...*21 / 20!  - 20-10! half-drops out even-numbered 40-22.
// = 2*39*2*37*2*35*...*2*21 / 10!

package problems

import "fmt"

func Problem015() string {
	var product uint64 = 1
	for i := uint64(21); i < 40; i += 2 {
		product *= 2 * i
	}
	for i := uint64(10); i > 1; i-- {
		product /= i
	}
	return fmt.Sprint(product)
}

func init() {
	Functions[15] = Problem015
}

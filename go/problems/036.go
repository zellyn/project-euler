// Project Euler Problem 036
//
// Find the sum of all numbers less than one million, which are
// palindromic in base 10 and base 2.

package problems

import "fmt"

func palin(n, base int) bool {
	if n%base == 0 {
		return false
	}
	rev := 0
	for i := n; i > 0; i /= base {
		rev = rev*base + i%base
	}
	return rev == n
}

func Problem036() string {
	sum := 0
	for i := 1; i < 1e6; i++ {
		if palin(i, 10) && palin(i, 2) {
			sum += i
		}
	}
	return fmt.Sprintf("%d", sum)
}

func init() {
	Functions[36] = Problem036
}

// Project Euler Problem 014
//
// Find the longest sequence using a starting number under one
// million.

package problems

import "fmt"

func length(n uint) uint {
	if n < 3 {
		return n
	}
	if n&1 == 1 {
		return 2 + length((3*n+1)>>1)
	}
	return 1 + length(n>>1)
}

func Problem014() string {
	var max, nmax uint
	for i := uint(3); i < 1e6; i += 4 {
		if l := length(i); l > max {
			max = l
			nmax = i
		}
	}
	return fmt.Sprint(nmax)
}

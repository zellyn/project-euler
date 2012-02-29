// Project Euler Problem 014
//
// Find the longest sequence using a starting number under one
// million.

package main

import "fmt"

func len(n uint) uint {
	if n < 3 {
		return n
	}
	if n&1 == 1 {
		return 2 + len((3*n+1)>>1)
	}
	return 1 + len(n>>1)
}

func main() {
	var max, nmax uint
	for i := uint(3); i < 1e6; i += 4 {
		if l := len(i); l > max {
			max = l
			nmax = i
		}
	}
	fmt.Println(nmax)
}

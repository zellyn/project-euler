// Project Euler Problem 044
//
// Find the smallest pair of pentagonal numbers whose sum and
// difference is pentagonal.

package problems

import (
	"fmt"
	"math"
)

func isPentagonal(p int) bool {
	n := int(math.Sqrt(float64(2 * p / 3)))
	for ; ; n++ {
		pp := n * (3*n - 1) / 2
		if pp > p {
			return false
		}
		if pp == p {
			return true
		}
	}
	panic("impossible!")
}

func Problem044() string {
	for k := 1; ; k++ {
		pk := k * (3*k - 1) / 2
		for j := 1; j < k; j++ {
			pj := j * (3*j - 1) / 2
			if isPentagonal(pk-pj) && isPentagonal(pk+pj) {
				return fmt.Sprintf("%d", pk-pj)
			}
		}
	}
	panic("Cannot reach")
}

func init() {
	Functions[44] = Problem044
}

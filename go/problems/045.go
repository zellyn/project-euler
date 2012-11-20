// Project Euler Problem 045
//
// After 40755, what is the next triangle number that is also
// pentagonal and hexagonal?

package problems

import (
	"fmt"
	"math"
)

func isTriangular64(t int64) bool {
	n := int64(math.Sqrt(float64(2 * t)))
	for ; ; n-- {
		tt := n * (n + 1) / 2
		if tt < t {
			return false
		}
		if tt == t {
			return true
		}
	}
	panic("impossible!")
}

func isHexagonal64(h int64) bool {
	n := int64(math.Sqrt(float64(h / 2)))
	for ; ; n++ {
		hh := n * (2*n - 1)
		if hh > h {
			return false
		}
		if hh == h {
			return true
		}
	}
	panic("impossible!")
}

func Problem045() string {
	for n := int64(166); ; n++ {
		p := n * (3*n - 1) / 2
		if isTriangular64(p) && isHexagonal64(p) {
			return fmt.Sprintf("%d", p)
		}
	}
	panic("reached")
}

func init() {
	Functions[45] = Problem045
}

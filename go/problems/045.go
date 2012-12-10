// Project Euler Problem 045
//
// After 40755, what is the next triangle number that is also
// pentagonal and hexagonal?

package problems

import (
	"fmt"

	"../sequence"
)

func Problem045() string {
	for n := int64(166); ; n++ {
		p := n * (3*n - 1) / 2
		if sequence.IsTriangular64(p) && sequence.IsHexagonal64(p) {
			return fmt.Sprintf("%d", p)
		}
	}
	panic("reached")
}

func init() {
	Functions[45] = Problem045
}

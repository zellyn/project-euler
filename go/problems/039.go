// Project Euler Problem 039
//
// If p is the perimeter of a right angle triangle, {a, b, c}, which
// value, for p ≤ 1000, has the most solutions?

package problems

import (
	"fmt"
	"math"
)

func Problem039() string {
	n, max := 0, 0
	counts := make(map[int]int)
	for a := 1; a < 333; a++ {
		for b := a + 1; b < 500; b++ {
			sq := a*a + b*b
			c := int(math.Sqrt(float64(sq)))
			if a+b+c <= 1000 && a*a+b*b == c*c {
				counts[a+b+c] += 1
				if counts[a+b+c] > max {
					n, max = a+b+c, counts[a+b+c]
				}
			}
		}
	}
	return fmt.Sprintf("%d", n)
}

func init() {
	Functions[39] = Problem039
}

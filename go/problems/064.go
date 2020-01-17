// Project Euler Problem 064
//
// How many continued fractions for N ≤ 10000 have an odd period?

package problems

import (
	"fmt"

	"github.com/zellyn/project-euler/go/contfrac"
)

func Problem064() string {
	count := 0
	for n := 1; n < 10000; n++ {
		if (len(contfrac.Sqrt(n))-1)%2 == 1 {
			count++
		}
	}
	return fmt.Sprint(count)
}

func init() {
	Functions[64] = Problem064
}

// Project Euler Problem 028
//
// What is the sum of both diagonals in a 1001 by 1001 spiral?

package problems

import "fmt"

func Problem028() string {
	sum := 1
	inc := 2
	n := 1
	for i := 0; i < 1001/2; i++ {
		for j := 0; j < 4; j++ {
			n += inc
			sum += n
		}
		inc += 2
	}
	return fmt.Sprintf("%d", sum)
}

func init() {
	Functions[28] = Problem028
}

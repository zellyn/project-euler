// Project Euler Problem 026
//
// Find the value of d < 1000 for which 1/d contains the longest
// recurring cycle.

package problems

import "fmt"

func repeatLength(i int) int {
	positionForQuotient := make(map[int]int)
	index, q := 0, 1
	for {
		for ; q < i ; {
			index++
			q *= 10
		}
		// Non-repeating
		if ((q % i) == 0) {
			return 0
		}
		q -= i * (q/i)
		if positionForQuotient[q] > 0 {
			return index - positionForQuotient[q]
		}
		positionForQuotient[q] = index
	}
	return 0
}

func Problem026() string {
	max, maxlen := 0, 0
	for i := 7; i < 1000; i++ {
		if length := repeatLength(i); length > maxlen {
			maxlen, max = length, i
		}
	}
	return fmt.Sprintf("%d", max)
}

func init() {
     Functions[26] = Problem026
}

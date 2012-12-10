// Project Euler Problem 061
//
// Find the sum of the only set of six 4-digit figurate numbers with a
// cyclic property.

package problems

import (
	"fmt"
)

type suffix struct {
	digits int
	mask   int
}

type suffixMap map[int][]suffix

func search(nextDigits, endDigits, used int, info suffixMap) int {
	if used == 0x1f {
		if nextDigits == endDigits {
			return 0
		}
		return -1
	}
	for _, suffix := range info[nextDigits] {
		if suffix.mask&used > 0 {
			continue
		}
		if sub := search(suffix.digits, endDigits, used|suffix.mask, info); sub > -1 {
			return nextDigits*100 + suffix.digits + sub
		}
	}
	return -1
}

func Problem061() string {
	info := make(suffixMap)
	for n := 1; n*(n+1)/2 <= 9999; n++ {
		for i := 0; i < 5; i++ {
			f := n * ((i+1)*n + 1 - i) / 2
			if f > 9999 {
				break
			}
			if f < 1000 {
				continue
			}
			info[f/100] = append(info[f/100], suffix{f % 100, 1 << uint(i)})
		}
	}
	// oct(19): 1045
	// oct(58): 9976
	for n := 19; n <= 58; n++ {
		oct := n * (3*n - 2)
		if s := search(oct%100, oct/100, 0, info); s > 0 {
			return fmt.Sprint(s + oct)
		}
	}
	return fmt.Sprint(0)
}

func init() {
	Functions[61] = Problem061
}

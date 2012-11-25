// Project Euler Problem 052
//
// Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x,
// and 6x, contain the same digits in some order.

package problems

import "fmt"

func digitCounts(n int) (result [10]int) {
	for ; n > 0; n /= 10 {
		result[n%10] += 1
	}
	return result
}

func Problem052() string {
	for n := 100; ; n++ {
		dc := digitCounts(n)
		found := true
		for i := 2; i <= 6; i++ {
			if digitCounts(n*i) != dc {
				found = false
				break
			}
		}
		if found {
			return fmt.Sprint(n)
		}
	}
	panic("unreachable")
}

func init() {
	Functions[52] = Problem052
}

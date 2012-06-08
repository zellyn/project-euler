// Project Euler Problem 017
//
// How many letters would be needed to write all the numbers in words
// from 1 to 1000?

package problems

import "fmt"

var lengths_ones []int = []int{0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8}
var lengths_tens []int = []int{0, 3, 6, 6, 5, 5, 5, 7, 6, 6}

func numLength(n int) int {
	switch {
	case n < 20:
		return lengths_ones[n]
	case n == 1000:
		return 11
	case n > 99:
		if n%100 == 0 {
			return numLength(n/100) + 7
		} else {
			return numLength(n/100) + 7 + 3 + numLength(n%100)
		}
	}
	return lengths_tens[n/10] + lengths_ones[n%10]
}

func Problem017() string {
	sum := 0
	for i := 1; i <= 1000; i++ {
		sum += numLength(i)
	}
	return fmt.Sprint(sum)
}

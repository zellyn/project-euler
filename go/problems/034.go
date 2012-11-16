// Project Euler Problem 034
//
// Find the sum of all numbers which are equal to the sum of the
// factorial of their digits.
//
// 9! == 362880
// 9! * 7 == 2540160, so 7 digits max
// 1999999: 1 + 6 * 9! == 2177281

package problems

import "fmt"

var factorials = []int{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}

func Check(n int) bool {
	sum, nn := 0, n
	for ; nn > 0; nn /= 10 {
		sum += factorials[nn%10]
	}
	return sum == n
}

func Problem034() string {
	sum := 0
	for n := 10; n < 2177281; n++ {
		if Check(n) {
			sum += n
		}
	}
	return fmt.Sprintf("%d", sum)
}

func init() {
	Functions[34] = Problem034
}

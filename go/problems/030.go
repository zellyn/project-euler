// Project Euler Problem 030
//
// Find the sum of all the numbers that can be written as the sum of
// fifth powers of their digits.
//
// 9 ** 5 * 6 = 354294, so we only have to check up to 354294.

package problems

import "fmt"

func SumOfFifthPowers(n int) (sum int) {
	for ; n > 0; n /= 10 {
		u := n % 10
		sum += (u * u * u * u * u)
	}
	return
}

func Problem030() string {
	sum := 0
	for n := 2; n < 354294; n++ {
		if n == SumOfFifthPowers(n) {
			sum += n
		}
	}
	return fmt.Sprintf("%d", sum)
}

func init() {
	Functions[30] = Problem030
}

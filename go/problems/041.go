// Project Euler Problem 041
//
// What is the largest n-digit pandigital prime that exists?

package problems

import (
	"fmt"

	"../primes"
)

func pandigitalN(n int) bool {
	mask := 0
	count := uint(0)
	for ; n > 0; n /= 10 {
		mask |= (1 << uint(n%10))
		count++
	}
	return mask == (1<<(count+1) - 2)
}

func Problem041() string {
	max := 0
	for n := 0; ; n++ {
		p := primes.Get(n)
		// sum(1..9) == 45, so 1..8 and 1..9 are divisible by 3
		if p > 7654321 {
			break
		}
		if pandigitalN(p) {
			max = p
		}
	}
	return fmt.Sprintf("%d", max)
}

func init() {
	Functions[41] = Problem041
}

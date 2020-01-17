// Project Euler Problem 037
//
// Find the sum of all eleven primes that are both truncatable from
// left to right and right to left.

package problems

import (
	"fmt"

	"github.com/zellyn/project-euler/go/primes"
)

func truncatable(n int) bool {
	// even digits kill it (except leading 2)
	for nn := n / 10; nn > 2; nn /= 10 {
		if nn&1 == 0 {
			return false
		}
	}
	for pow10 := int(10); pow10 < n; pow10 *= 10 {
		if !primes.IsPrime(n%pow10) || !primes.IsPrime(n/pow10) {
			return false
		}
	}
	return true
}

func Problem037() string {
	count, sum := 0, 0
	for n := 4; count < 11; n++ {
		if p := primes.Get(n); truncatable(p) {
			sum += p
			count++
		}
	}
	return fmt.Sprintf("%d", sum)
}

func init() {
	Functions[37] = Problem037
}

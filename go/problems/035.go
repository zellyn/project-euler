// Project Euler Problem 035
//
// How many circular primes are there below one million?

package problems

import (
	"fmt"
	"math"

	"../primes"
)

func allRotationsPrime(n int) bool {
	for nn := n / 10; nn > 0; nn /= 10 {
		if nn&1 == 0 {
			return false
		}
	}
	l := int(math.Log10(float64(n)))
	mult := int(math.Pow10(l))
	for i := 0; i < l; i++ {
		n = n/10 + mult*(n%10)
		if !primes.IsPrime(n) {
			return false
		}
	}
	return true
}

func Problem035() string {
	count := 0
	for n := 0; ; n++ {
		if p := primes.Get(n); p < 1e6 {
			if allRotationsPrime(p) {
				count++
			}
		} else {
			break
		}
	}
	return fmt.Sprintf("%d", count)
}

func init() {
	Functions[35] = Problem035
}

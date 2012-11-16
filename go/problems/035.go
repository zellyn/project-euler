// Project Euler Problem 035
//
// How many circular primes are there below one million?

package problems

import (
	"fmt"
	"math"

	"../primes"
)

func allRotationsPrime(n int64) bool {
	l := int(math.Log10(float64(n)))
	mult := int64(math.Pow10(l))
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

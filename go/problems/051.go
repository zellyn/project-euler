// Project Euler Problem 051
//
// Find the smallest prime which, by changing the same part of the
// number, can form eight different primes.

package problems

import (
	"fmt"

	"github.com/zellyn/project-euler/go/primes"
)

func upperDigits(n int) (result int) {
	for n = n / 10; n > 0; n /= 10 {
		result |= (1 << uint(n%10))
	}
	return result
}

var empty = []int{}

// Generate all patterns that can be created by replacing the given digit.
// Started out as strings, with '*' representing "replace me".
// Then changed to base-11 digits, with 10 representing "replace me".
func patternsForDigit(n, digit int) (result []int) {
	if n < 10 {
		switch n {
		case digit:
			return []int{n, 10}
		default:
			return []int{n}
		}
	}
	for _, p := range patternsForDigit(n/10, digit) {
		result = append(result, p*11+n%10)
		if n%10 == digit {
			result = append(result, p*11+10)
		}
	}
	return result
}

func patternsForNumber(n int) (result []int) {
	digits := upperDigits(n)
	for i := 0; i <= 9; i++ {
		if digits&1 != 0 {
			for _, p := range patternsForDigit(n/10, i)[1:] {
				result = append(result, p*10+n%10)
			}
		}
		digits >>= 1
	}
	return
}

func Problem051() string {
	patToPrimes := make(map[int][]int)
	for n := 100; ; n++ {
		p := primes.Get(n)
		if p < 10000 {
			continue
		}
		for _, pat := range patternsForNumber(p) {
			patToPrimes[pat] = append(patToPrimes[pat], p)
			if len(patToPrimes[pat]) == 8 {
				return fmt.Sprint(patToPrimes[pat][0])
			}
		}
	}
	return fmt.Sprint(0)
}

func init() {
	Functions[51] = Problem051
}

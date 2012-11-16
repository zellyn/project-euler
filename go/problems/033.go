// Project Euler Problem 033
//
// Discover all the fractions with an unorthodox cancelling method.

package problems

import "fmt"

func Curious(a, b int) bool {
	ha, la := a/10, a%10
	hb, lb := b/10, b%10
	switch {
	case la*lb == 0:
		return false
	case ha == hb && a*lb == b*la:
		return true
	case ha == lb && a*hb == b*la:
		return true
	case la == hb && a*lb == b*ha:
		return true
	case la == lb && a*hb == b*ha:
		return true
	}
	return false
}

func Gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return Gcd(b, a%b)
}

func Problem033() string {
	top, bottom := 1, 1

	for a := 11; a < 99; a++ {
		for b := a + 1; b < 100; b++ {
			if Curious(a, b) {
				top *= a
				bottom *= b
			}
		}
	}
	return fmt.Sprintf("%d", bottom/Gcd(top, bottom))
}

func init() {
	Functions[33] = Problem033
}

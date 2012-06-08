// Project Euler Problem 009
//
// Find the only Pythagorean triplet, {a, b, c}, for which a + b + c =
// 1000.

package problems

import "fmt"

func Problem009() string {
	for a := 1; a < 998; a++ {
		for b := a + 1; b < 999; b++ {
			if c := 1000 - a - b; c*c == a*a+b*b {
				return fmt.Sprint(a * b * c)
			}
		}
	}
	return ""
}

// Project Euler Problem 024
//
// What is the millionth lexicographic permutation of the digits 0, 1,
// 2, 3, 4, 5, 6, 7, 8 and 9?

package problems

import "github.com/zellyn/project-euler/go/util"

func NthPerm(digits string, index int) string {
	if len(digits) == 1 {
		return digits
	}
	fac := util.Factorial(len(digits) - 1)
	i := index / fac
	return digits[i:i+1] + NthPerm(digits[:i]+digits[i+1:], index%fac)
}

func Problem024() string {
	initial := "0123456789"
	return NthPerm(initial, 999999)
}

func init() {
	Functions[24] = Problem024
}

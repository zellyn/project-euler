// Project Euler Problem 048
//
// Find the last ten digits of 1^1 + 2^2 + ... + 1000^1000.

package problems

import "fmt"

func Problem048() string {
	sum := int64(0)
	for i := int64(1); i <= 1000; i++ {
		littleSum := i
		for j := int64(1); j < i; j++ {
			littleSum *= i
			littleSum %= 10000000000
		}
		sum += littleSum
		sum %= 10000000000
	}
	return fmt.Sprint(sum)
}

func init() {
	Functions[48] = Problem048
}

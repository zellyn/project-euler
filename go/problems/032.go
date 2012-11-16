// Project Euler Problem 032
//
// Find the sum of all numbers that can be written as pandigital
// products.

package problems

import "fmt"

func Match(numbers ...int) bool {
	mask := 1 // 0 is out!
	for _, number := range numbers {
		for ; number > 0; number /= 10 {
			mask |= 1 << uint(number%10)
		}
	}
	return (mask == 0x3ff)
}

func Problem032() string {
	found := make(map[int]bool)
	// Lengths 1, 4, 4
	for a := 2; a <= 9; a++ {
		for b := 1234; b <= 9876; b++ {
			if a*b <= 9876 && Match(a, b, a*b) {
				found[a*b] = true
			}
		}
	}
	// Lengths 2, 3, 4
	for a := 12; a <= 98; a++ {
		for b := 123; b <= 987; b++ {
			if a*b <= 9876 && Match(a, b, a*b) {
				found[a*b] = true
			}
		}
	}
	sum := 0
	for k, _ := range found {
		sum += k
	}
	return fmt.Sprintf("%d", sum)
}

func init() {
	Functions[32] = Problem032
}

// Project Euler Problem 023
//
// Find the sum of all the positive integers which cannot be written
// as the sum of two abundant numbers.

package problems

import (
	"fmt"
	"sort"

	"github.com/zellyn/project-euler/go/primes"
)

func isAbundant(candidate int) bool {
	sum := 0
	for _, divisor := range primes.ProperDivisors(candidate) {
		sum += divisor
	}
	return sum > candidate
}

func findAbundants() (result map[int]bool) {
	result = make(map[int]bool)
	for i := 12; i < 28123-12; i++ {
		if isAbundant(i) {
			result[i] = true
		}
	}
	return
}

func Problem023() string {
	summable := make([]bool, 28124)
	abundantsMap := findAbundants()
	abundants := make([]int, 0, len(abundantsMap))
	for a := range abundantsMap {
		abundants = append(abundants, a)
	}
	sort.Ints(abundants)
	for index, a1 := range abundants {
		for _, a2 := range abundants[index:] {
			if a1+a2 > 28123 {
				break
			}
			summable[a1+a2] = true
		}
	}
	sum := 0
	for i := 0; i <= 28123; i++ {
		if !summable[i] {
			sum += i
		}
	}
	return fmt.Sprintf("%d", sum)
}

func init() {
	Functions[23] = Problem023
}

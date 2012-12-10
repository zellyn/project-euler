// Project Euler Problem 062
//
// Find the smallest cube for which exactly five permutations of its
// digits are cube.

package problems

import (
	"fmt"
	"sort"
)

func highestPermutation64(n int64) (result int64) {
	digits := []int{}
	for ; n > 0; n /= 10 {
		digits = append(digits, int(n%10))
	}
	sort.Ints(digits)
	for i := range digits {
		result = result*10 + int64(digits[len(digits)-1-i])
	}
	return result
}

func Problem062() string {
	smallestCubes := make(map[int64]int64)
	cubeCounts := make(map[int64]int)
	for n := int64(0); ; n++ {
		cube := n * n * n
		key := highestPermutation64(cube)
		if smallestCubes[key] == 0 {
			smallestCubes[key] = cube
		}
		cubeCounts[key]++
		if cubeCounts[key] == 5 {
			return fmt.Sprint(smallestCubes[key])
		}
	}
	panic("unreachable")
}

func init() {
	Functions[62] = Problem062
}

// Project Euler Problem 049
//
// Find arithmetic sequences, made of prime terms, whose four digits
// are permutations of each other.

package problems

import (
	"fmt"
	"sort"

	"../primes"
)

func lowestPermutation(n int) (result int) {
	digits := []int{}
	for ; n > 0; n /= 10 {
		digits = append(digits, n%10)
	}
	sort.Ints(digits)
	for _, digit := range digits {
		result = result*10 + digit
	}
	return result
}

func Problem049() string {
	permutations := make(map[int][]int)
	n := 25
	for ; ; n++ {
		p := primes.Get(n)
		if p < 1000 {
			continue
		}
		if p > 9999 {
			break
		}
		lowest := lowestPermutation(p)
		permutations[lowest] = append(permutations[lowest], p)
	}
	for _, v := range permutations {
		l := len(v)
		if l < 3 {
			continue
		}
		sort.Ints(v)
		for i := 0; i < l-2; i++ {
			for j := i + 1; j < l-1; j++ {
				if v[i] == 1487 && v[j] == 4817 {
					continue
				}
				for k := j + 1; k < l; k++ {
					if v[k]-v[j] == v[j]-v[i] {
						return fmt.Sprintf("%d%d%d", v[i], v[j], v[k])
					}
				}
			}
		}
	}
	return fmt.Sprint(0)
}

func init() {
	Functions[49] = Problem049
}

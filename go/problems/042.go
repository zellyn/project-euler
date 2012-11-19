// Project Euler Problem 042
//
// How many triangle words does the list of common English words
// contain?

package problems

import "fmt"

func wordSum(s string) int {
	sum := 0
	for _, c := range s {
		sum += int(c-'A') + 1
	}
	return sum
}

func isTriangular(c int) bool {
	for n := 1; ; n++ {
		t := n * (n + 1) / 2
		if t > c {
			return false
		}
		if t == c {
			return true
		}
	}
	panic("Unreachable")
}

func Problem042() string {
	words, err := readNames("../data/p042_words.txt")
	if err != nil {
		return err.Error()
	}
	count := 0
	for _, word := range words {
		if isTriangular(wordSum(word)) {
			count++
		}
	}
	return fmt.Sprintf("%d", count)
}

func init() {
	Functions[42] = Problem042
}

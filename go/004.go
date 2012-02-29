// Project Euler Problem 004
//
// Find the largest palindrome made from the product of two 3-digit numbers.

package main

import "fmt"

func isPalindrome(n int) bool {
	s := fmt.Sprint(n)
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		if s[i] != s[j] {
			return false
		}
	}
	return true
}

func main() {
	max := 0
	for i := 101; i <= 999; i++ {
		for j := i; j <= 999; j++ {
			s := i * j
			if s > max && isPalindrome(s) {
				max = s
			}
		}
	}
	fmt.Println(max)
}

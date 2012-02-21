// Project Euler Problem 009
//
// Find the only Pythagorean triplet, {a, b, c}, for which a + b + c =
// 1000.

package main

import "fmt"

func main() {
	for a := 1; a < 998; a++ {
		for b := a + 1; b < 999; b++ {
			if c := 1000 - a - b; c*c == a*a+b*b {
				fmt.Println(a * b * c)
				return
			}
		}
	}
}

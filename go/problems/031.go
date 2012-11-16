// Project Euler Problem 031
//
// Investigating combinations of English currency denominations.

package problems

import "fmt"

var denominations = []int{200, 100, 50, 20, 10, 5, 2, 1}

func WaysToChange(target int, coins []int) (result int) {
	if len(coins) == 1 || target == 0 {
		return 1
	}
	for i := 0; i <= target/coins[0]; i++ {
		rest := coins[1:]
		result += WaysToChange(target-i*coins[0], rest)
	}
	return
}

func Problem031() string {
	return fmt.Sprintf("%d", WaysToChange(200, denominations))
}

func init() {
	Functions[31] = Problem031
}

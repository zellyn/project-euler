// Project Euler Problem 053
//
// How many values of C(n,r), for 1 ≤ n ≤ 100, exceed one-million?

package problems

import "fmt"

func choicesGt1e6(n int) int {
	choices := 1
	for r := 1; r <= n/2; r++ { // Halfway only: it's a mirror-image
		choices *= (n - r + 1)
		choices /= r
		if choices > 1000000 {
			// All the rest (on both sides of the halfway mark)
			return n + 1 - r*2
		}
	}
	return 0
}

func Problem053() string {
	count := 0
	for n := 23; n <= 100; n++ {
		count += choicesGt1e6(n)
	}
	return fmt.Sprint(count)
}

func init() {
	Functions[53] = Problem053
}

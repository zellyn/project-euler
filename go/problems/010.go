// Project Euler Problem 010
//
// Calculate the sum of all the primes below two million.

package problems

import (
	"fmt"

	"github.com/zellyn/project-euler/go/primes"
)

func Problem010() string {
	var sum int64 = 0
	i := 0
	for {
		p := primes.Get64(i)
		i++
		if p >= 2000000 {
			break
		}
		sum += p
	}
	return fmt.Sprint(sum)
}

func init() {
	Functions[10] = Problem010
}

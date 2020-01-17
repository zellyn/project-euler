// Project Euler Problem 021
//
// Evaluate the sum of all amicable pairs under 10000.

package problems

import (
	"fmt"

	"github.com/zellyn/project-euler/go/primes"
)

func Problem021() string {
	sum := 0
	for i := 2; i < 10000; i++ {
		sd := primes.SumDivisors(i)
		if sd > i && primes.SumDivisors(sd) == i {
			sum += i + sd
		}
	}
	return fmt.Sprint(sum)
}

func init() {
	Functions[21] = Problem021
}

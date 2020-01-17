// Project Euler Problem 007
//
// Find the 10001st prime.

package problems

import (
	"fmt"

	"github.com/zellyn/project-euler/go/primes"
)

func Problem007() string {
	return fmt.Sprint(primes.Get(10000))
}

func init() {
	Functions[7] = Problem007
}

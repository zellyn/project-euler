// Project Euler Problem 003
//
// Find the largest prime factor of a composite number.

package problems

import (
	"fmt"

	"github.com/zellyn/project-euler/go/primes"
)

func Problem003() string {
	var product int64 = 600851475143
	factors := primes.PrimeFactors64(product)
	return fmt.Sprint(factors[len(factors)-1].Prime)
}

func init() {
	Functions[3] = Problem003
}

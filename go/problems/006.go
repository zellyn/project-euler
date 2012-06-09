// Project Euler Problem 006
//
// What is the difference between the sum of the squares and the
// square of the sums?

package problems

import "fmt"

func Problem006() string {
	sum, sumsq := 0, 0
	for i := 1; i <= 100; i++ {
		sum += i
		sumsq += i * i
	}
	sq := sum * sum
	return fmt.Sprint(sq - sumsq)
}

func init() {
     Functions[6] = Problem006
}

// Project Euler Problem 043
//
// Find the sum of all pandigital numbers with an unusual sub-string
// divisibility property.

package problems

import "fmt"

func newMask(oldMask int, num int64, digits int) int {
	mask := oldMask
	for ; digits > 0; digits-- {
		bit := 1 << uint(num%10)
		if mask&bit > 0 {
			return -1
		}
		mask |= bit
		num /= 10
	}
	return mask
}

func choicesLeft(mask int) (result []int64) {
	for i := int64(0); i < 10; i++ {
		if mask&(1<<uint(i)) == 0 {
			result = append(result, i)
		}
	}
	return result
}

var divisors = []int64{13, 11, 7, 5, 3, 2}

func sumsFrom(soFar int64, mask int, pow10 int64, index int) (sum int64) {
	if index == 6 {
		d1 := choicesLeft(mask)[0]
		return soFar + d1*pow10
	}
	lastDigits := soFar / (pow10 / 100)
	for _, n := range choicesLeft(mask) {
		d3 := n*int64(100) + lastDigits
		if d3%divisors[index] > 0 {
			continue
		}
		sum += sumsFrom(n*pow10+soFar, mask|1<<uint(n), pow10*10, index+1)
	}
	return sum
}

func Problem043() string {
	sum := int64(0)
	for d890 := int64(17); d890 <= 986; d890 += 17 {
		mask := newMask(0, d890, 3)
		if mask < 0 {
			continue
		}
		sum += sumsFrom(d890, mask, 1000, 0)
	}
	return fmt.Sprintf("%d", sum)
}

func init() {
	Functions[43] = Problem043
}

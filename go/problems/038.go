// Project Euler Problem 038
//
// What is the max 1 to 9 pandigital that can be formed by
// multiplying a fixed number by 1, 2, 3, ... ?

package problems

import (
	"fmt"
	"math"
)

func updateMaskAndNum(mask, fullNum, newNum int) (int, int) {
	pow10 := int(math.Pow10(int(math.Log10(float64(newNum)))))
	for newNum > 0 {
		digit := newNum / pow10
		bit := 1 << uint(digit)
		if mask&bit > 0 {
			return 0, 0
		}
		mask |= bit
		fullNum = fullNum*10 + digit
		newNum -= pow10 * digit
		pow10 /= 10
	}
	return mask, fullNum
}

func Problem038() string {
	max := 0
	for i := 1; i < 9876; i++ {
		mask := 1
		num := 0
		for n := 1; ; n++ {
			mask, num = updateMaskAndNum(mask, num, i*n)
			if mask == 0 {
				break
			}
			if mask == 0x3ff {
				if num > max {
					max = num
				}
				break
			}
		}
	}
	return fmt.Sprintf("%d", max)
}

func init() {
	Functions[38] = Problem038
}

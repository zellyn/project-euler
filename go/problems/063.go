// Project Euler Problem 063
//
// How many n-digit positive integers exist which are also an nth
// power?

// 9**21 is the last time 9**n has n digits. (9**22 is 21 digits long)
// 10**n always has n+1 digits

package problems

import (
	"fmt"
	"math/big"
)

func Problem063() string {
	count := 1 // 1**1
	for base := int64(2); base <= 9; base++ {
		bigBase := big.NewInt(base)
		for n := 1; n <= 21; n++ {
			bigPower := big.NewInt(int64(n))
			bigPower.Exp(bigBase, bigPower, nil)
			l := len(bigPower.String())
			if l < n {
				break
			}
			if l == n {
				count++
			}
		}
	}
	return fmt.Sprint(count)
}

func init() {
	Functions[63] = Problem063
}

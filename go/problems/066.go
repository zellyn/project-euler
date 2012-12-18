// Project Euler Problem 066
//
// Investigate the Diophantine equation x2 − Dy2 = 1.

package problems

import (
	"fmt"
	"math/big"

	"../contfrac"
)

// A little reading reveals that we can use continued fraction
// convergents of the square root of n.
// http://en.wikipedia.org/wiki/Pell%27s_equation
func Pell(n int) (h, k *big.Int) {
	sqrt := contfrac.Sqrt(n)
	if len(sqrt) == 1 {
		return
	}
	for convergent := range contfrac.Convergents(contfrac.SqrtSeq(n)) {
		h, k := convergent[0], convergent[1]
		// if h*h - n *  k * k == 1
		hh := big.NewInt(0).Mul(h, h)
		nkk := big.NewInt(0).Mul(big.NewInt(int64(n)), big.NewInt(0).Mul(k, k))
		test := big.NewInt(0).Sub(hh, nkk)
		if big.NewInt(1).Cmp(test) == 0 {
			return h, k
		}
	}
	panic("unreachable")
}

func Problem066() string {
	max := big.NewInt(0)
	maxd := 0
	for d := 2; d < 1001; d++ {
		h, _ := Pell(d)
		if h != nil {
			if h.Cmp(max) > 0 {
				max = h
				maxd = d
			}
		}
	}
	return fmt.Sprint(maxd)
}

func init() {
	Functions[66] = Problem066
}

package contfrac

import (
	"math/big"
)

func E() <-chan int {
	c := make(chan int)
	go func() {
		c <- 2
		i := 2
		for {
			c <- 1
			c <- i
			c <- 1
			i += 2
		}
	}()
	return c
}

// Enumerate the convergents of a continued fraction, using
// http://en.wikipedia.org/wiki/Fundamental_recurrence_formulas
func Convergents(in <-chan int) <-chan [2]*big.Int {
	out := make(chan [2]*big.Int)

	go func() {
		b_nm1 := big.NewInt(int64(<-in))
		A_nm1 := big.NewInt(0).Set(b_nm1)
		B_nm1 := big.NewInt(1)
		out <- [2]*big.Int{A_nm1, B_nm1}

		b_n := big.NewInt(int64(<-in))
		A_n := big.NewInt(0).Mul(b_n, b_nm1)
		A_n.Add(A_n, big.NewInt(1))
		B_n := big.NewInt(0).Set(b_n)
		out <- [2]*big.Int{A_n, B_n}

		for {
			b_np1 := big.NewInt(int64(<-in))
			A_np1 := big.NewInt(0).Mul(b_np1, A_n)
			A_np1.Add(A_np1, A_nm1)
			B_np1 := big.NewInt(0).Mul(b_np1, B_n)
			B_np1.Add(B_np1, B_nm1)
			out <- [2]*big.Int{A_np1, B_np1}
			A_nm1, B_nm1, b_nm1 = A_n, B_n, b_n
			A_n, B_n, b_n = A_np1, B_np1, b_np1
		}
	}()
	return out
}

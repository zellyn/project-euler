// Project Euler Problem 040
//
// Finding the nth digit of the fractional part of the irrational
// number.

package problems

import "fmt"

func Problem040() string {
	c := make(chan int)
	quit := make(chan bool)

	go func() {
		pow10 := 1
		for n := 1; ; n++ {
			if n >= pow10*10 {
				pow10 *= 10
			}
			for nn, pp := n, pow10; pp > 0; {
				digit := nn / pp
				nn -= pp * digit
				pp /= 10
				select {
				case <-quit:
					return
				case c <- digit:
				}
			}
		}
	}()

	prod, pos := 1, 1
	for i := 1; i < 1000001; i++ {
		digit := <-c
		if i == pos {
			prod *= digit
			pos *= 10
		}
	}
	quit <- true
	return fmt.Sprintf("%d", prod)
}

func init() {
	Functions[40] = Problem040
}

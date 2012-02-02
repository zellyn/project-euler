// Project Euler Problem 001
//
// Add all the natural numbers below one thousand that are multiples
// of 3 or 5.

package main

import "fmt"

func main() {
  total := 0
  for i := 0; i < 1000; i++ {
    if (i % 3) * (i % 5) == 0 {
      total += i
    }
  }
  fmt.Println(total)
}

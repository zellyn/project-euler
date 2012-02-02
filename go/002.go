// Project Euler Problem 002
//
// By considering the terms in the Fibonacci sequence whose values do
// not exceed four million, find the sum of the even-valued terms.

package main

import "fmt"

func main() {
  sum := 0
  for f1, f2 := 1, 1; f1 <= 4000000; f1, f2 = f1 + f2, f1 {
    if f1 % 2 == 0 {
      sum += f1
    }
  } 
  fmt.Println(sum)
}

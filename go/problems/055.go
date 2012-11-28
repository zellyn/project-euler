// Project Euler Problem 055
//
// How many Lychrel numbers are there below ten-thousand?

package problems

import "fmt"

func addReversed(num []byte) []byte {
	carry := byte(0)
	l := len(num)
	result := make([]byte, l)
	copy(result, num)
	for i := 0; i < len(num); i++ {
		sum := carry + result[i] + num[l-i-1]
		result[i] = sum % 10
		carry = sum / 10
	}
	if carry > 0 {
		result = append(result, carry)
	}
	return result
}

func makeSlice(n int) (result []byte) {
	for ; n > 0; n /= 10 {
		result = append(result, byte(n%10))
	}
	return result
}

func slicePalindromic(slice []byte) bool {
	l := len(slice)
	for i := 0; i < l/2; i++ {
		if slice[i] != slice[l-i-1] {
			return false
		}
	}
	return true
}

func isLychrel(n int) bool {
	count := 0
	slice := makeSlice(n)
	for ; count < 50; count++ {
		slice = addReversed(slice)
		if slicePalindromic(slice) {
			return false
		}
	}
	return true
}

func Problem055() string {
	count := 0
	for i := 1; i < 10000; i++ {
		if isLychrel(i) {
			count++
		}
	}
	return fmt.Sprint(count)
}

func init() {
	Functions[55] = Problem055
}

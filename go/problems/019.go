// Project Euler Problem 019
//
// How many Sundays fell on the first of the month during the
// twentieth century?

package problems

import "fmt"

func Problem019() string {
	months := [...]int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	sundays := 0
	day := 366 // Monday is 0, 1900 had 366 days
	for year := 1901; year < 2001; year++ {
		isLeap := (year%4 == 0) && ((year%100 != 0) || year%400 == 0)
		for month := 0; month < 12; month++ {
			if day%7 == 6 {
				sundays++
			}
			day += months[month]
			if month == 1 && isLeap {
				day += 1
			}
		}
	}
	return fmt.Sprint(sundays)
}

func init() {
     Functions[19] = Problem019
}

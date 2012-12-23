// Project Euler Problem 068
//
// What is the maximum 16-digit string for a "magic" 5-gon ring?

//      o0._         o1
//         _.i0._   /
//    _.i4'      `i1
// o4'    \      /
//         i3---i2---o2
//          \
//           o3

// Start with the lowest outside digit and work clockwise.

package problems

import "fmt"

func or10(lowest, num byte) byte {
	if lowest == num {
		return 10
	}
	return num
}

func inners(c chan string, o0, o1, o2, o3, o4 byte) {
	used := 1<<o0 | 1<<o1 | 1<<o2 | 1<<o3 | 1<<o4
	for i0 := byte(9); i0 > 0; i0-- {
		if used&(1<<i0) > 0 {
			continue
		}
		used := used | (1 << i0)
		for i1 := byte(9); i1 > 0; i1-- {
			if used&(1<<i1) > 0 {
				continue
			}
			used := used | (1 << i1)
			sum := o0 + i0 + i1
			i2 := sum - o1 - i1
			if i2 > 9 || used&(1<<i2) > 0 {
				continue
			}
			used = used | (1 << i2)
			i3 := sum - o2 - i2
			if i3 > 9 || used&(1<<i3) > 0 {
				continue
			}
			used = used | (1 << i3)
			i4 := sum - o3 - i3
			if i4 > 9 || used&(1<<i4) > 0 || i0+i4+o4 != sum {
				continue
			}
			s0 := fmt.Sprintf("%d%d%d", o0, i0, i1)
			s1 := fmt.Sprintf("%d%d%d", o1, i1, i2)
			s2 := fmt.Sprintf("%d%d%d", o2, i2, i3)
			s3 := fmt.Sprintf("%d%d%d", o3, i3, i4)
			s4 := fmt.Sprintf("%d%d%d", o4, i4, i0)
			c <- fmt.Sprint(s0, s1, s2, s3, s4)
		}
	}
}

// Give the possible outer values, starting at o0 as the lowest.
// 10 must be present. Otherwise we count down in the order that will yield
// larger stringified values first (9, 8, ..., 10).
func outers(o0 byte) <-chan string {
	c := make(chan string)
	go func() {
		for o1 := byte(9); o1 >= o0; o1-- {
			used := 1 << o1
			for o2 := byte(9); o2 >= o0; o2-- {
				if used&(1<<o2) > 0 {
					continue
				}
				used := used | (1 << o2)
				for o3 := byte(9); o3 >= o0; o3-- {
					if used&(1<<o3) > 0 {
						continue
					}
					used := used | (1 << o3)
					for o4 := byte(9); o4 >= o0; o4-- {
						if used&(1<<o4) > 0 {
							continue
						}
						used := used | (1 << o4)
						if used&(1<<o0) == 0 {
							continue
						}
						inners(c, o0, or10(o0, o1), or10(o0, o2), or10(o0, o3), or10(o0, o4))
					}
				}
			}
		}
		close(c)
	}()
	return c
}

func Problem068() string {
	largest := "0"
	for lowestDigit := byte(6); lowestDigit > 0; lowestDigit-- {
		for s := range outers(lowestDigit) {
			if s > largest {
				largest = s
			}
		}
		if largest != "0" {
			return largest
		}
	}
	return "0"
}

func init() {
	Functions[68] = Problem068
}

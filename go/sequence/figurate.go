package sequence

import (
	"math"
)

func IsTriangular64(t int64) bool {
	n := int64(math.Sqrt(float64(2 * t)))
	for ; ; n-- {
		tt := n * (n + 1) / 2
		if tt < t {
			return false
		}
		if tt == t {
			return true
		}
	}
	panic("impossible!")
}

func IsHexagonal64(h int64) bool {
	n := int64(math.Sqrt(float64(h / 2)))
	for ; ; n++ {
		hh := n * (2*n - 1)
		if hh > h {
			return false
		}
		if hh == h {
			return true
		}
	}
	panic("impossible!")
}

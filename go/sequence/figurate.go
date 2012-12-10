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

func IsSquare64(s int64) bool {
	sqrt := int64(math.Sqrt(float64(s)))
	return sqrt*sqrt == s
}

func IsPentagonal(p int64) bool {
	n := int64(math.Sqrt(2 / 3 * float64(p)))
	for ; ; n++ {
		pp := n * (3*n - 1) / 2
		if pp > p {
			return false
		}
		if pp == p {
			return true
		}
	}
	panic("impossible")
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

func IsHeptagonal64(h int64) bool {
	n := int64(math.Sqrt(2 / 5 * float64(h)))
	for ; ; n++ {
		hh := n * (5*n - 3) / 2
		if hh > h {
			return false
		}
		if hh == h {
			return true
		}
	}
	panic("impossible")
}

func IsOctagonal64(o int64) bool {
	n := int64(math.Sqrt(float64(o / 3)))
	for ; ; n++ {
		oo := n * (3*n - 2)
		if oo > o {
			return false
		}
		if oo == o {
			return true
		}
	}
	panic("impossible!")
}

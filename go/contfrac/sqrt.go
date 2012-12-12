// Continued Fractions
package contfrac

import "math"

// http://www.mcs.surrey.ac.uk/Personal/R.Knott/Fibonacci/cfINTRO.html#sqrtalgsalg
// Cribbed from my python solution!
func Sqrt(n int) (result []int) {
	s := int(math.Sqrt(float64(n)))
	result = []int{s}
	if s*s == n {
		return
	}

	r := 0
	d := 1
	sn := s

	for {
		// (√n + r) / d = sn + 1/x
		// rn = sn * d - r
		// x = d / (√n - rn) * (√n + rn)/(√n + rn)
		// x = d (√n + rn) / n - rn**2
		// dn = (n - rn**2) / d
		// r,d = rn,dn

		rn := sn*d - r
		dn := (n - rn*rn) / d
		r, d = rn, dn
		sn = (s + r) / d

		if d > 1 {
			result = append(result, sn)
		} else {
			result = append(result, 2*s)
			return
		}
	}
	panic("unreachable")
}

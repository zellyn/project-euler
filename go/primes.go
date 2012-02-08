package primes

import (
	"math"
	"sort"
)

var primes []int64 = []int64{2, 3, 5}
var last int64 = 5
var inc int64 = 2

func Get(index int) int64 {
	for index >= len(primes) {
		add()
	}
	return primes[index]
}

func IsPrime(candidate int64) bool {
	for last < candidate {
		add()
	}
	if last == candidate {
		return true
	}
	index := sort.Search(len(primes), func(i int) bool { return primes[i] >= candidate })
	return primes[index] == candidate
}

func LazyIsPrime(candidate int64) bool {
	if last >= candidate {
		return IsPrime(candidate)
	} else {
		s := int64(math.Sqrt(float64(candidate) + 0.01))
		for last < s {
			add()
		}
		for i := 0; primes[i] <= s; i++ {
			if candidate%primes[i] == 0 {
				return false
			}
		}
	}
	return true
}

func add() {
	for {
		last += inc
		inc = 6 - inc
		limit := int64(math.Sqrt(float64(last) + 0.01))
		for pos := 0; ; pos++ {
			p := primes[pos]
			if last%p == 0 {
				break
			}
			if p > limit {
				// fmt.Println(last)
				primes = append(primes, last)
				return
			}
		}
	}
}

func PrimeFactors(product int64) []int64 {
	if LazyIsPrime(product) {
		return []int64{product}
	}
	var result []int64
	for _, p := range primes {
		limit := int64(math.Sqrt(float64(product) + 0.01))
		if product == 1 {
			return result
		}
		if p > limit {
			result = append(result, product)
			return result
		}
		for product%p == 0 {
			result = append(result, p)
			product /= p
		}
	}
	return result
}

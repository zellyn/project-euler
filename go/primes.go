package primes

import (
	"sort"
)

var primes []int64 = []int64{2, 3, 5}
var last int64 = 5
var inc int64 = 2

func add() {
	for {
		last += inc
		inc = 6 - inc
		for _, p := range primes {
			if last%p == 0 {
				break
			}
			if p*p > last {
				primes = append(primes, last)
				return
			}
		}
	}
}

func Get(index int) int64 {
	for index >= len(primes) {
		add()
	}
	return primes[index]
}

func IsPrime(candidate int64) bool {
	if last >= candidate {
		index := sort.Search(len(primes), func(i int) bool { return primes[i] >= candidate })
		return primes[index] == candidate
	}
	for last*last <= candidate {
		add()
	}
	for _, p := range primes {
		if candidate%p == 0 {
			return false
		}
	}
	return true
}

func PrimeFactors(product int64) []int64 {
	if IsPrime(product) {
		return []int64{product}
	}
	var result []int64
	for _, p := range primes {
		if product == 1 {
			return result
		}
		if p*p > product {
			return append(result, product)
		}
		for product%p == 0 {
			result = append(result, p)
			product /= p
		}
	}
	return result
}

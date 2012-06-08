package primes

import (
	"sort"
)

var primes []int64 = []int64{2, 3, 5}
var last int64 = 5
var inc int64 = 2

type Factor struct {
	Prime int64
	Count int
}

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

func PrimeFactors(product int64) []Factor {
	if IsPrime(product) {
		return []Factor{{product, 1}}
	}
	var result []Factor
	for _, p := range primes {
		if product == 1 {
			return result
		}
		if p*p > product {
			return append(result, Factor{product, 1})
		}
		count := 0
		for product%p == 0 {
			count++
			product /= p
		}
		result = append(result, Factor{p, count})
	}
	return result
}

func SumDivisors(product int64) int64 {
	factors := PrimeFactors(product)
	sum := int64(1)
	for _, factor := range factors {
		mult := int64(1)
		for i, oldsum := 0, sum; i < factor.Count; i++ {
			mult *= factor.Prime
			sum += mult * oldsum
		}
	}
	return sum - product
}

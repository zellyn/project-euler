package primes

import (
	"sort"
)

var primes []int = []int{2, 3, 5}
var last int = 5
var inc int = 2

type Factor struct {
	Prime int
	Count int
}

var primes64 []int64 = []int64{2, 3, 5}
var last64 int64 = 5
var inc64 int64 = 2

type Factor64 struct {
	Prime int64
	Count int
}

func add() {
	for {
		last += inc
		inc = 6 - inc
		for _, p := range primes[2:] {
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

func Get(index int) int {
	for index >= len(primes) {
		add()
	}
	return primes[index]
}

func IsPrime(candidate int) bool {
	if candidate > 2 && candidate&1 == 0 {
		return false
	}
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

func PrimeFactors(product int) []Factor {
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
		if count > 0 {
			result = append(result, Factor{p, count})
		}
	}
	return result
}

// ProperDivisors Returns all factors of product.
func ProperDivisors(product int) (result []int) {
	result = append(result, 1)
	for _, factor := range PrimeFactors(product) {
		for _, oldFactor := range result {
			pow := 1
			for i := 0; i < factor.Count; i++ {
				pow *= factor.Prime
				newFactor := oldFactor * pow
				if newFactor != product {
					result = append(result, newFactor)
				}
			}
		}
	}
	return
}

func SumDivisors(product int) int {
	factors := PrimeFactors(product)
	sum := 1
	for _, factor := range factors {
		mult := 1
		for i, oldsum := 0, sum; i < factor.Count; i++ {
			mult *= factor.Prime
			sum += mult * oldsum
		}
	}
	return sum - product
}

func add64() {
	for {
		last64 += inc64
		inc64 = 6 - inc64
		for _, p := range primes64[2:] {
			if last64%p == 0 {
				break
			}
			if p*p > last64 {
				primes64 = append(primes64, last64)
				return
			}
		}
	}
}

func Get64(index int) int64 {
	for index >= len(primes64) {
		add64()
	}
	return primes64[index]
}

func IsPrime64(candidate int64) bool {
	if candidate > 2 && candidate&1 == 0 {
		return false
	}
	if last64 >= candidate {
		index := sort.Search(len(primes64), func(i int) bool { return primes64[i] >= candidate })
		return primes64[index] == candidate
	}
	for last64*last64 <= candidate {
		add64()
	}
	for _, p := range primes64 {
		if candidate%p == 0 {
			return false
		}
	}
	return true
}

func PrimeFactors64(product int64) []Factor64 {
	if IsPrime64(product) {
		return []Factor64{{product, 1}}
	}
	var result []Factor64
	for _, p := range primes64 {
		if product == 1 {
			return result
		}
		if p*p > product {
			return append(result, Factor64{product, 1})
		}
		count := 0
		for product%p == 0 {
			count++
			product /= p
		}
		if count > 0 {
			result = append(result, Factor64{p, count})
		}
	}
	return result
}

// ProperDivisors Returns all factors of product.
func ProperDivisors64(product int64) (result []int64) {
	seen := map[int64]bool{
		1:       true,
		product: true,
	}
	result = append(result, 1)
	for _, factor := range PrimeFactors64(product) {
		for i := 0; i < factor.Count; i++ {
			for _, oldFactor := range result {
				if newFactor := oldFactor * factor.Prime; !seen[newFactor] {
					seen[newFactor] = true
					result = append(result, newFactor)
				}
			}
		}
	}
	return
}

func SumDivisors64(product int64) int64 {
	factors := PrimeFactors64(product)
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

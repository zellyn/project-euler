package primes

import (
	"sort"
	"testing"

	"github.com/google/go-cmp/cmp"
)

func TestProperDivisors(t *testing.T) {
	got := ProperDivisors(36)
	sort.Ints(got)
	want := []int{1, 2, 3, 4, 6, 9, 12, 18}
	if !cmp.Equal(got, want) {
		t.Errorf("want ProperDivisors(36)=%v; got %v", want, got)
	}

	sum := 0
	flip := 1
	for i := 2; i <= 10000; i++ {
		dvs := ProperDivisors(i)
		for _, dv := range dvs {
			sum += dv * flip
		}
		flip = -flip
	}

	wantSum := 20564126
	if wantSum != sum {
		t.Errorf("want sum=%d; got %d", wantSum, sum)
	}
}

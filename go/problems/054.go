// Project Euler Problem 054
//
// How many hands did player one win in the game of poker?

package problems

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strings"
)

const VALUES = "23456789TJQKA"
const SUITS = "HDCS"

type Hand struct {
	suits  int   // Base-4 representation of suits, multiples of 11111_4 are flushes
	values int32 // Bitmask of values seen: Ace is (1<<0) and (1<<13)
	cards  []int // Cards seen: units is card value, tens is (# times seen - 1)
}

func (h *Hand) add(cardStr string) {
	value := strings.Index(VALUES, cardStr[:1])
	suit := strings.Index(SUITS, cardStr[1:])

	// Add to values seen
	h.values |= (1 << uint(value+1))
	h.values |= h.values >> 13 // Copy Ace to bit 0

	// Add to suits seen
	h.suits = h.suits*4 + suit

	// Add to cards seen
	for i := range h.cards {
		if h.cards[i]%15 == value {
			h.cards[i] += 15
			return
		}
	}
	h.cards = append(h.cards, value)
}

func (h Hand) valueSummary() (result int) {
	for i := len(h.cards) - 1; i >= 0; i-- {
		result = result*10 + h.cards[i]/15 + 1
	}
	return result
}

func (h Hand) score() (result float32) {
	sort.Ints(h.cards) // Value with most cards last
	summary := h.valueSummary()
	var stackScore float32

	for _, card := range h.cards {
		stackScore = (stackScore + float32(card%15)) / 15
	}

	// Royal flush
	if score := h.royalFlush(); score > 0 {
		return 9 + score
	}
	// Straight flush
	if score := h.straightFlush(); score > 0 {
		return 8 + score
	}
	// Four of a kind
	if summary == 41 {
		return 7 + stackScore
	}
	// Full house
	if summary == 32 {
		return 6 + stackScore
	}
	// Flush
	if h.suits%341 == 0 {
		return 5 + stackScore
	}
	// Straight
	if score := h.straight(); score > 0 {
		return 5 + score
	}
	// Three of a kind
	if summary == 311 {
		return 3 + stackScore
	}
	// Two pairs
	if summary == 221 {
		return 2 + stackScore
	}
	// One pair
	if summary == 2111 {
		return 1 + stackScore
	}
	// High card
	return stackScore
}

func (h Hand) royalFlush() float32 {
	if h.values>>12 != 3 { // Ace, King
		return 0
	}
	return h.straightFlush()
}

func (h Hand) straightFlush() float32 {
	if h.suits%341 > 1 {
		return 0
	}
	return h.straight()
}

func (h Hand) straight() float32 {
	for i := uint(0); i < 10; i++ {
		if (h.values>>i)&0x1f == 0x1f {
			return float32(i) / 15
		}
	}
	return 0
}

func readLines(filename string) (result []string, err error) {
	var file *os.File
	if file, err = os.Open(filename); err != nil {
		return nil, err
	}
	defer file.Close()
	r := bufio.NewReader(file)
	for line, _, err := r.ReadLine(); err != io.EOF; line, _, err = r.ReadLine() {
		if err != nil {
			return nil, err
		}
		result = append(result, string(line))
	}
	return result, err
}

func Problem054() string {
	lines, err := readLines("../data/p054_poker.txt")
	if err != nil {
		return err.Error()
	}
	count := 0
	for _, line := range lines {
		var hand1, hand2 Hand
		cardStrings := strings.Split(line, " ")
		for i := 0; i < 5; i++ {
			hand1.add(cardStrings[i])
			hand2.add(cardStrings[i+5])
		}
		if hand1.score() > hand2.score() {
			count++
		}
	}
	return fmt.Sprint(count)
}

func init() {
	Functions[54] = Problem054
}

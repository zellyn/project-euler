// Project Euler Problem 059
//
// Using a brute force attack, can you decrypt the cipher using XOR
// encryption?

package problems

import (
	"fmt"
	"strconv"
)

var trigrams map[int]int

func init() {
	// From http://www.cs.chalmers.se/Cs/Grundutb/Kurser/krypto/en_stat.html
	var sampleTrigrams = []string{
		" th", "he ", "the", "ed ", "nd ", " an", "and", " to", "ng ",
		" he", "er ", "ing", "to ", " of", "at ", "of ", "is ", "d t",
		" in", " hi", " ha", "e t", "as ", "her", "in "}
	trigrams = make(map[int]int)
	for _, s := range sampleTrigrams {
		trigrams[int(s[0])<<14+int(s[1])<<7+int(s[2])] = 1
	}
}

func readCommaSeparatedBytes(filename string) (result []byte, err error) {
	strings, err := readNames("../data/p059_cipher1.txt")
	if err != nil {
		return nil, err
	}
	for _, s := range strings {
		if i, err := strconv.ParseInt(s, 10, 8); err == nil {
			result = append(result, byte(i))
		} else {
			return nil, err
		}
	}
	return result, nil
}

func xor(bytes []byte, mask byte, offset int) (unlikely bool) {
	for i := offset; i < len(bytes); i += 3 {
		bytes[i] ^= mask
		b := bytes[i]
		unlikely = unlikely || (b < ' ') || (b > '~')
	}
	return unlikely
}

func countSampleTrigrams(bytes []byte) (result int) {
	trigram := 0
	for _, b := range bytes {
		trigram = trigram&0x3fff<<7 | int(b)
		result += trigrams[trigram]
	}
	return result
}

func Problem059() string {
	bytes, err := readCommaSeparatedBytes("../data/p059_cipher1.txt")
	if err != nil {
		return err.Error()
	}
	max, maxMsg := 0, 0
	for a := 0; a < 256; a++ {
		unlikelyA := xor(bytes, byte(a), 0)
		if !unlikelyA {
			for b := 0; b < 256; b++ {
				unlikelyB := xor(bytes, byte(b), 1)
				if !unlikelyB {
					for c := 0; c < 256; c++ {
						unlikelyC := xor(bytes, byte(c), 2)
						if !unlikelyC {
							if count := countSampleTrigrams(bytes); count > max {
								max = count
								maxMsg = 0
								for _, bb := range bytes {
									maxMsg += int(bb)
								}
							}
						}
						xor(bytes, byte(c), 2)
					}
				}
				xor(bytes, byte(b), 1)
			}
		}
		xor(bytes, byte(a), 0)
	}
	return fmt.Sprint(maxMsg)
}

func init() {
	Functions[59] = Problem059
}

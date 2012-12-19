// Project Euler Problem 067
//
// Using an efficient algorithm find the maximal sum in the triangle?

package problems

import (
	"fmt"
	"strconv"
	"strings"
)

func readTriangle(filename string) (result []int, err error) {
	lines, err := readLines(filename)
	if err != nil {
		return nil, err
	}
	for _, line := range lines {
		for _, s := range strings.Split(line, " ") {
			i, err := strconv.Atoi(s)
			if err != nil {
				return nil, err
			}
			result = append(result, i)
		}
	}
	return result, nil
}

func Problem067() string {
	triangle, err := readTriangle("../data/p067_triangle.txt")
	if err != nil {
		panic(err)
	}
	return fmt.Sprint(maxTriPath(triangle))
}

func init() {
	Functions[67] = Problem067
}

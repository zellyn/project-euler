// Project Euler Problem 022
//
// What is the total of all the name scores in the file of first
// names?

package problems

import (
	"encoding/csv"
	"fmt"
	"os"
	"sort"
)

// Read a whole file into the memory and store it as array of lines
func readNames(path string) (names []string, err error) {
	var file *os.File
	if file, err = os.Open(path); err != nil {
		return
	}
	defer file.Close()

	reader := csv.NewReader(file)
	if names, err = reader.Read(); err != nil {
		return
	}
	return
}

func letterSum(s string) (sum int) {
	for _, c := range s {
		sum += int(c-'A') + 1
	}
	return
}

func Problem022() string {
	names, err := readNames("../data/p022_names.txt")
	if err != nil {
		return err.Error()
	}
	sort.Strings(names)
	sum := 0
	for index, name := range names {
		sum += (index + 1) * letterSum(name)
	}
	return fmt.Sprint(sum)
}

func init() {
	Functions[22] = Problem022
}

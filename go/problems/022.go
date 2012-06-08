// Project Euler Problem 022
//
// What is the total of all the name scores in the file of first
// names?

package problems

import (
	"bufio"
	"bytes"
	"fmt"
	"io"
	"os"
)

// Read a whole file into the memory and store it as array of lines
func readLines(path string) (lines []string, err error) {
	var (
		file   *os.File
		part   []byte
		prefix bool
	)
	if file, err = os.Open(path); err != nil {
		return
	}
	defer file.Close()

	reader := bufio.NewReader(file)
	buffer := bytes.NewBuffer(make([]byte, 0))
	for {
		if part, prefix, err = reader.ReadLine(); err != nil {
			break
		}
		buffer.Write(part)
		if !prefix {
			lines = append(lines, buffer.String())
			buffer.Reset()
		}
	}
	if err == io.EOF {
		err = nil
	}
	return
}

func Problem022() string {
	names, err := readLines("../data/p022_names.txt")
	if err != nil {
		return ""
	}
	return fmt.Sprint(len(names))
}

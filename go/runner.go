package main

import (
	"fmt"
	"os"
	"strconv"

	"github.com/zellyn/project-euler/go/problems"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Usage: runner <problem number>")
		os.Exit(1)
	}
	problem, err := strconv.ParseInt(os.Args[1], 10, 16)
	if err != nil {
		fmt.Println("Usage: runner <problem number>")
		os.Exit(1)
	}
	fn, ok := problems.Functions[problem]
	if !ok {
		fmt.Println("Unknown problem:", problem)
		os.Exit(1)
	}
	fmt.Println(fn())
}

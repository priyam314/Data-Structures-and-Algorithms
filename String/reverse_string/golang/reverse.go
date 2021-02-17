package main

import (
	"fmt"
	"os"
)

func main() {
	arg := os.Args[1]
	var a string = reverse(string(arg))
	fmt.Println(a)
}
func reverse(s string) (result string) {
	for _, v := range s {
		result = string(v) + result
	}
	return
}

package main

import (
	"fmt"
	"strconv"
	"strings"
)

// [1,2,[4,[7,8],9],4] -> [1,2,4,7,8,9,4]
func main() {
	var str INPUT = "[1,2,[4,[7,8],9],[4,3]]"
	p := make(NestedList, 0)
	//fmt.Println(convertToNestedList(str.split(),p))
	val, _ := convertToNestedList(str.split(), p)
	fmt.Println(Flatten(val))
}

type INPUT string

func (input INPUT) split() []string {
	return strings.Split(string(input[1:len(input)-1]), ",")
}

var count int

func convertToNestedList(input []string, p NestedList) (NestedList, int) {
	i := 0
	for count < len(input) {
		if input[i][len(input[i])-1] == ']' {
			fmt.Println("]:", input[i], i)
			val, _ := strconv.Atoi(string(input[i][0]))
			p = append(p, NestedElem{value: val, nestedVal: nil})
			count++
			break
		} else if input[i][0] == '[' {
			fmt.Println("[:", input[i], i)
			new_p := make(NestedList, 0)
			input[i] = input[i][1:]
			val, _ := strconv.Atoi(string(input[i][0]))
			var nestedVal NestedList
			nestedVal, count = convertToNestedList(input[i:], new_p)
			p = append(p, NestedElem{value: val, nestedVal: nestedVal})
			i++
			count++
		} else if input[i] != "[" {
			fmt.Println("ntng:", input[i], i)
			val, _ := strconv.Atoi(input[i])
			p = append(p, NestedElem{nestedVal: nil, value: val})
			i++
			count++
		}
	}
	return p, count
}

type NestedElem struct {
	nestedVal NestedList
	value     int
}
type NestedList []NestedElem

func Flatten(arr NestedList) []int {
	var output []int
	for _, v := range arr {
		if v.nestedVal == nil {
			output = append(output, v.value)
		} else if v.nestedVal != nil {
			output = append(output, Flatten(v.nestedVal)...)
		}
	}
	return output
}

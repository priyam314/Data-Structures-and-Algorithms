package main

import (
	"fmt"
	"os"
)

func main(){
	fmt.Println(reverse(os.Args[1:]))
}
func reverse(arr []string) (result string){
	for _,v := range arr{
		result = v +" "+ result 
	}
	return 
}

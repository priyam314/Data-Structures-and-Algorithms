package main
import (
	"fmt"
	"os"
)
func main(){
	output := distributeCandies(os.Args[1:])
	fmt.Println(output)
}
func distributeCandies(candyType []string) int {
    var candies = make(map[string]int,len(candyType))
    for _,v := range candyType {
        candies[v]++
    }
    return Min(len(candyType)/2,len(candies))
}
func Min(a int,b int) int {
    if a>=b{
        return b
    }else{
        return a
    }
}

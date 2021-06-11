package main
import (
	"testing"
)
type testStruct struct{
	a int64
	b int64
}
func TestFibE(t *testing.T){
	testCase := []testStruct{
	{1,1},
	{2,1},
	{3,2},
	{4,3},
	{5,5},
	{6,8},
	}
	for _, v := range testCase{
		if fibE(v.a)==v.b{
			t.Logf(" CORRECT expected %v, got %v",v.b,fibE(v.a))
		}else{
			t.Errorf("WRONG expected %v, got %v", v.b, fibE(v.a))
		}
	}
}

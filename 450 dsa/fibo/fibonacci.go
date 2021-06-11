package main
import (
	"strings"
	"strconv"
)
func fibN(a int64) int64 {
	if a<=2{
		return 1
	}else{
		return fibN(a-1)+fibN(a-2)
	}
}
func fibM(a int64, memo []int64) int64 {
	if memo[a]!=0{
		return memo[a]
	}else if a<=2{
		return 1
	}else{
		memo[a] = fibM(a-1,memo)+fibM(a-2,memo)
		return memo[a]
	}
}
func fibE(a int64) int64 {
	if a==1 || a==2{
		return 1
	}
	Matrix := matrixExp(strings.Split(strconv.FormatInt(a-1,2),""))
	return Matrix[0][0]
}
func matrixExp(reducedList []string) [][]int64{
	matrix := [][]int64{{1,1},{1,0}}
	var matrixList [][][]int64
	length := len(reducedList)
	matrixSquare := matrix
	i:=length-1
	for i>=0{
		if (i==length-1 && reducedList[i]=="1"){
			matrixList = append(matrixList, matrix)
		}else{
			if (reducedList[i]=="1"){
				matrixList = append(matrixList, matrixSquare)
			}
		}
		matrixSquare = matrixMul(matrixSquare, matrixSquare)
		i--
	}
	nextMatrix := matrixList[0]
	for i:=0;i<len(matrixList)-1;i++{
		nextMatrix = matrixMul(nextMatrix, matrixList[i+1])
	}
	return nextMatrix
}
func matrixMul(matrix1 ,matrix2 [][]int64) [][]int64 {
	return [][]int64{
		{matrix1[0][0]*matrix2[0][0] + matrix1[0][1]*matrix2[1][0],matrix1[0][0]*matrix2[0][1] + matrix1[0][1]*matrix2[1][1]},
		{matrix1[1][0]*matrix2[0][0] + matrix1[1][1]*matrix2[1][0],matrix1[1][0]*matrix2[0][1] + matrix1[1][1]*matrix2[1][1]},
	}
}

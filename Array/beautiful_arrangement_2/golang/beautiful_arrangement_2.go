func constructArray(n int, k int) []int {
    if k>=n{    return []int{}  }
    temp := make([]int,n)
    for i:= 0;i<n;i++{  temp[i]=i+1 }
    tempSlice := make([]int,0)
    for j := 0;j<k/2+1;j++{
        if temp[j]==temp[k-j]{
            tempSlice = append(tempSlice,temp[j])
        }
        tempSlice = append(tempSlice,temp[j], temp[k-j])
    }
    for i:=0;i<k+1;i++{ temp[i] = tempSlice[i]  }
    return temp
}

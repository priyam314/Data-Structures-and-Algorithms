class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        if k>=n:
            return []
        temp = [i for i in range(1,n+1)]
        tempSlice = []
        for i in range(k//2+1):
            if temp[i]==temp[k-i]:
                tempSlice.append(temp[i])
            tempSlice.append(temp[i])
            tempSlice.append(temp[k-i])
        for i in range(k+1):
            temp[i]=tempSlice[i]
        return temp

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        if (k>=n){
            return vector<int>{};
        }
        vector<int> temp(n);
        for (int i=0;i<n;i++){
            temp[i]=i+1;
        }
        vector<int> tempSlice;
        for (int i=0 ;i<k/2+1;i++){
            if (temp[i]==temp[k-i]){
                tempSlice.push_back(temp[i]);
            }
            tempSlice.push_back(temp[i]);
            tempSlice.push_back(temp[k-i]);
        }
        for (int i =0;i<k+1;i++){
            temp[i]=tempSlice[i];
        }
        return temp;
    }
};

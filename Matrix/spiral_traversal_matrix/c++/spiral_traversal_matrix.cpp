#include <iostream>
#include <vector>
using namespace std;

class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> array(r*c,0);
        int i,k=0,l=0,t=0;
        
        while(k<r && l<c){
            for (i=l;i<c;i++){
                array[t]=matrix[k][i];
                t++;
            }
            k++;
            for(i=k;i<r;i++){
                array[t]=matrix[i][c-1];
                t++;
            }
            c--;
            if (k<r){
                for(i = c-1; i>=l ;i--){
                    array[t]=matrix[r-1][i];
                    t++;
                }
                r--;
            }
            if(l<c){
                for(i = r-1 ; i>=k ; i--){
                    array[t]=matrix[i][l];
                    t++;
                }
                l++;
            }
        }
        return array;
    }
};

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int r,c;
		cin>>r>>c;
		vector<vector<int>> matrix(r);
		
		for (int i=0; i<r ;i++){
			matrix[i].assign(c,0);
			for (int j=0;j<c;j++){
				cin>>matrix[i][j];
			}
		}
		
		Solution ob;
		vector<int> result = ob.spirallyTraverse(matrix,r,c);
		for(int i=0 ;i<result.size();i++){
			cout<<result[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main(){
	int first,second;
	cin>>first>>second;
	
	vector<int> arr1(first);
	vector<int> arr2(second);
	
	for (int i=0;i<first;i++){
		cin>>arr1[i];
	}
	for (int i=0;i<second;i++){
		cin>>arr2[i];
	}
	int i=0,j=0,count=0;
	while(i<first && j<second){
		if (arr1[i]<arr2[j]){
			cout<<arr1[i++]<<" ";
		}else if (arr2[j]<arr1[i]){
			cout<<arr2[j++]<<" ";
		}else{
			cout<<arr2[j++]<<" ";
			i++;
		}
		count++;
	}
	while(i<first){
		cout<<arr1[i++]<<" ";
		count++;
	}
	while(j<second){
		cout<<arr2[j++]<<" ";
		count++;
	}
	
	cout<<"\n"<<count<<endl;
	return 0;
}

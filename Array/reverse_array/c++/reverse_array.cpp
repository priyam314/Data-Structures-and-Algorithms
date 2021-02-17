#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, int* argv[]){
	vector<int>array(argc-1,0);
	int i=0;
	for (auto x : argv[1]){
		array[i]=x;
		i++;
	}
	reverse(array.begin(),array.end());
	for (auto i=array.begin();i!=array.end();i++){
		cout<<*i<<" ";
	}
	return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int candiesDistribute(vector<int> candyType,int n){
	unordered_map<int,int> candies;
	for (auto x : candyType){
		candies[x]++;
	}
	return min(n/2,(int)candies.size());
}
int main(int argc, char *argv[]){
	vector<int>array(argc-1,0);
	for (int i=1;i<argc;i++){
		array[i-1]=atoi(argv[i]);
	}
	cout<<candiesDistribute(array,argc-1)<<endl;
	return 0;
}


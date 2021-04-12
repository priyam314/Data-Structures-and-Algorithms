// command line input
// n k

import std.stdio;
import std.conv;

void main(string[] args){
	writeln(arrangements(to!int(args[1]),to!int(args[2])));
}
int[] arrangements(int n, int k){
	if (k>=n){
		return [];
	}
	int[] temp;
	for (int i=0; i<n;i++){
		temp ~= i+1;
	}
	int[] tempSlice;
	for (int i = 0 ;i<k/2+1;i++){
		if (temp[i]==temp[k-i]){
			tempSlice ~=temp[i];
		}
		tempSlice ~= temp[i];
		tempSlice ~= temp[k-i];
	}
	for (int i=0;i<k+1;i++){
		temp[i]=tempSlice[i];
	}
	return temp;
}

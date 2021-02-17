#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string reversed(string);

int main(int argc, char** argv){
	cout<<reversed(argv[1])<<endl;
	return 0;
}

string reversed(string s){
	reverse(s.begin(),s.end());
	return s;
}

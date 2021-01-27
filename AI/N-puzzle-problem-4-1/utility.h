#pragma once

#include <iostream>
#include <vector>
using namespace std;

bool right(vector<vector<int>>,int);
bool left(int);
bool up(int);
bool down(vector<vector<int>> ,int);
void printm(string,vector<vector<int>>);
int manhattanDist(vector<vector<int>>,vector<vector<int>>);
int displaced(vector<vector<int>>,vector<vector<int>>);
int difference(vector<vector<int>>,vector<vector<int>>);
int redundant(string,vector<vector<int>>,vector<vector<int>>);
bool sameVectors(vector<vector<int>>,vector<vector<int>>);
bool isThere(vector<vector<vector<int>>>,vector<vector<int>>);
int Move(vector<vector<int>>,vector<vector<int>>,int,int,string,string );
string minimum(int , int , int , int );
bool process(vector<vector<int>>,vector<vector<int>>,int,int,string);
bool makeMove(vector<vector<int>>,vector<vector<int>>,int,int,int,int,string);

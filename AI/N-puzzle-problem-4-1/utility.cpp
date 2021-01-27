#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
#include "utility.h"
using namespace std;

vector<vector<vector<int>>>storage; 
int totalSteps=0;

//declaration
//bool makeMove(vector<vector<int>>,vector<vector<int>>,int,int,int,int,string);

bool right(vector<vector<int>> initial,int checkx){
  if ((checkx+1)<initial.size())
    return true;
  return false;
}
bool left(int checkx){
  if ((checkx-1)>-1)
    return true;
  return false;
}
bool up(int checky){
  if ((checky-1)>-1)
    return true;
  return false;
}
bool down(vector<vector<int>> initial,int checky){
  if ((checky+1)<initial.size())
    return true;
  return false;
}
void printm(string str,vector<vector<int>>initial){
  cout<<str<<endl;
  for (int i=0;i<initial.size();i++){
    for (int j=0;j<initial.size();j++)
      cout<<initial[i][j]<<" ";
    cout<<"\n";
  }
}
int manhattanDist(vector<vector<int>>initial,vector<vector<int>>goal){
  int count=0;
  struct Coordinate{
    int x,y;
    Coordinate(int xx, int yy){
      x=xx;
      y=yy;
    }
  };
  unordered_map<int,pair<int,int>>initialMap;
  unordered_map<int,pair<int,int>>goalMap;
  for (int i=0; i<initial.size(); i++){
    for (int j=0; j<initial.size(); j++){
      pair<int,int> i1(j,i);
      pair<int,int> g1(j,i);
      initialMap[initial[i][j]]=i1;
      goalMap[goal[i][j]]=g1;
    }
  }
  for (auto e:goalMap){
    count = count + abs(e.second.first-initialMap[e.first].first)+abs(e.second.second-initialMap[e.first].second);
  }
  return count;
}
int displaced(vector<vector<int>>initial,vector<vector<int>>goal){
  int count=0;
  for (int i=0; i<initial.size(); i++){
    for (int j =0; j<initial.size(); j++){
      if (initial[i][j]!=goal[i][j])
        count++;
    }
  }
  return count;
}
int difference(vector<vector<int>>initial,vector<vector<int>>goal){
  //return manhattanDist(initial,goal);
  return displaced(initial,goal);                             
  //return manhattanDist(initial,goal)+displaced(initial,goal); 
}
int redundant(string str,vector<vector<int>>initial,vector<vector<int>>goal){
  storage.push_back(initial);
  return difference(initial,goal);
}
bool sameVectors(vector<vector<int>>initial,vector<vector<int>>goal){
  for (int i=0;i<initial.size();i++){
    for (int j=0;j<initial.size();j++){
      if (initial[i][j]!=goal[i][j])
        return false;
    }
  }
  return true;
}
bool isThere(vector<vector<vector<int>>>storage,vector<vector<int>>initial){
  if (storage.size()==0)
    return false;
  for (auto x:storage){
    if (sameVectors(initial,x))
      return true;
  }
  return false;
}
int Move(vector<vector<int>>initial,vector<vector<int>>goal,int checkx,int checky,string str,string move){
  if (str == "right"){
    if (right(initial,checkx)){
      swap(initial[checky][checkx],initial[checky][checkx+1]);
      if (!isThere(storage,initial))
        return redundant(move,initial,goal);
    }
    return INT_MAX;  
  }else if(str == "left"){
    if (left(checkx)){
      swap(initial[checky][checkx],initial[checky][checkx-1]);
      if (!isThere(storage,initial))
        return redundant(move,initial,goal);
    }
    return INT_MAX;
  }else if(str == "up"){
    if (up(checky)){
      swap(initial[checky][checkx],initial[checky-1][checkx]);
      if(!isThere(storage,initial))
        return redundant(move,initial,goal);
    }
    return INT_MAX;
  }else if(str == "down"){
    if (down(initial,checky)){
      swap(initial[checky][checkx],initial[checky+1][checkx]);
      if(!isThere(storage,initial))
        return redundant(move,initial,goal);
    }
    return INT_MAX;
  }else
      cout<<"nhi ho paya"<<endl;
    return INT_MAX;
}
string minimum(int L, int R, int U, int D){
  int mini[4] = {L,R,U,D}; 
  int smallest=INT_MAX,check;
  for (int i=0;i<4;i++){
    if(smallest>mini[i]){
      smallest=mini[i];
      check=i;
    }
  }
  if (check==0)
    return "L";
  else if(check==1)
    return "R";
  else if(check==2)
    return "U";
  else if(check==3)
    return "D";
  return "";
}

bool process(vector<vector<int>>initial,vector<vector<int>>goal,int checkx,int checky,string move){
  if (sameVectors(initial,goal)){
    cout<<"\n"<<"MATCHED!!"<<"\n"<<endl;
    cout<<"Total Steps : "<<totalSteps<<endl;
    return true;
  }else{
    int L=Move(initial,goal,checkx,checky,"left",move+"left->");
    int R=Move(initial,goal,checkx,checky,"right",move+"right->");
    int U=Move(initial,goal,checkx,checky,"up",move+"up->");
    int D=Move(initial,goal,checkx,checky,"down",move+"down->");
    string mini = minimum(L,R,U,D);

    cout<<mini<<endl;
    
    cout<<endl;
    if(mini == "L"){
      totalSteps++;
      return makeMove(initial,goal,checkx,checky,checkx-1,checky,move);
    } 
    else if(mini == "R"){
      totalSteps++;
      return makeMove(initial,goal,checkx,checky,checkx+1,checky,move);
    }
    else if(mini == "U"){
      totalSteps++;
      return makeMove(initial,goal,checkx,checky,checkx,checky-1,move);
    }
    else if(mini == "D"){
      totalSteps++;
      return makeMove(initial,goal,checkx,checky,checkx,checky+1,move);
    }
    else
      return false;
  }
}
bool makeMove(vector<vector<int>>initial,vector<vector<int>>goal,int checkx,int checky,int newCheckx,int newChecky,string move){
  swap(initial[checky][checkx],initial[newChecky][newCheckx]);
  printm("initial matrix",initial);
  cout<<endl;
  return process(initial,goal,newCheckx,newChecky,move);
}
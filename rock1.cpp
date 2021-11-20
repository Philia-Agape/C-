#include <algorithm>
#include <cassert>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <utility>
#include <bitset>
#include <forward_list>
#include <list>
#include <stack>
#include <iterator>
#include <iostream>
#include<bits/stdc++.h>

using namespace std;



void solve(int t){
	int N;
        string S;
	cin >> N >> S;
	
	map<string,string> num = { {"01","2"}, {"12","3"}, {"23","4"}, {"34","5"}, {"45","6"}, 
	{"56","7"}, {"67","8"}, {"78","9"} , {"89","0"}, {"90","1"} };

	
	//int index = 0;
	string buffer = "", ini = S, ss;
	while(buffer != S){
	   for(auto i=num.begin(); i!= num.end(); ++i){   
	      for(int j=0; j<S.size(); ++j){
	         ss = S.substr(j,2);
	         if(num.find(ss) != num.end() && i->second == num[ss]){
	            S.replace(j,2,num[ss]);
	         }
	      }
           
           }
           buffer = ini;
           ini = S;
        }
        cout << "Case #" << t << ": " << S << "\n";
        return;
}




// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int main() {
   //map<int,int> sum;
   vector<int> A = {0,0,0,2,3,8,1,4,0,4};
   int ans = 1, odd = 0; //p: num of path
   vector<vector<int>> path (A.size(), vector<int> {0});
   //deque<deque<int>> path;
   for(int i=1; i<A.size(); ++i){
      //path[i].push_back(0);
      for(int j=0; j<A.size(); ++j){
         if(A[i] == path[j].back()){
            //one-direction!
            path[j].push_back(i);
            break;
         }      
      }
   }
   
   
   for(int i=0; i<A.size(); ++i){
      odd = 0;
      for(int j=0; j<path[i].size(); ++j){
         if(path[i][j] % 2 == 1){
            ++odd;
         }
         if(odd > 1){
            break;
         }
         ans = (ans < j+1) ? j+1 : ans;
      }   
   }
   
   cout << "Longest path with one odd node is: " << ans << "\n";
   return 0;
}

/*
bool odd = false;
    stack<int> path;
    for(auto it=graph[0].begin(); it!=graph[0].end(); ++it){
       odd = false;
       path = {};
       path.push(0);
       path.push(*it);
       if (*it % 2 == 1) odd = true;
       index = 0; 
       while (!odd || index % 2 == 0){
          ans = (ans > path.size()) ? ans : path.size();
          index = path.top();
          for(auto itr=graph[index].begin(); itr !=graph[index].end(); ++itr){
            temp = graph.push();
            
          } 
       }
    }
*/    

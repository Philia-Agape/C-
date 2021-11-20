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
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
#include <algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int main() {
   //map<int,int> sum;
   vector<int> A = {5,3,1,3,2,3};
   vector<int> subsum (A.size()-1,0);
   int ans = 0;
   for(int i=0;i<A.size()-1;++i){
      subsum[i] = A[i]+A[i+1];
   }
   map<int,stack<int>> sum; 
   map<int,stack<int>> mymap; 
   for(int i=0; i<subsum.size();++i){ 
      if(sum[subsum[i]].empty()){
         sum[subsum[i]].push(i);
      }
      else if(i-sum[subsum[i]].top() != 1){
         sum[subsum[i]].push(i);
      }
   } 
   for(auto it=sum.begin(); it !=sum.end(); ++it){
      ans = (ans > sum[it->first].size()) ? ans : sum[it->first].size();
      cout << "sum[" << it->first << "] = ";
      while(!sum[it->first].empty()){
         cout << sum[it->first].top() << "\t";
         sum[it->first].pop();
      }
      cout << "\n";
   }
   cout << "ans = " << ans << "\n";
   return ans;
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

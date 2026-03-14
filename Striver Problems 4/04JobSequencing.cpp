#include<bits/stdc++.h>
using namespace std;
// THIS IS IN GFG 
// Wow i solved this on my own and very proud of it
// Striver gave the same solution
// But this can be optimized with using DSU Data Structure(which will be taught in graph)

//Time Complexity O(nlogn) + O(n^2)(in worst case)
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
        for(int i=0;i<deadline.size();i++){
            pq.push({profit[i],deadline[i]});
        }
        int n=deadline.size();
        unordered_map<int,int> mp;
        vector<bool> visited(n,false);
        for(int i=1;i<=n;i++){
            mp[i]=i-1; // Mapping the index of visited array
        }
        int countJob=0;
        int maxProfit=0;
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            int deadline=p.second;
            int profit=p.first;
            
            int index=mp[deadline]>=0? mp[deadline]:-1; // Get the index and then decrement;
            for(int i=index;i>=0;i--){
                if(visited[i]==false){
                    visited[i]=true;
                    maxProfit+=profit;
                    countJob++;
                    mp[deadline]=i-1;  // Tiny optimization
                    break;
                }
            }
        }

        return {countJob,maxProfit};
    }
};
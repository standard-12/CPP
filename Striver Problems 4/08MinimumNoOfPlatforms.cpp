#include<bits/stdc++.h>
using namespace std;

// This was my solution 
// I am seeing at any time how many elements are there in priority queue the maximum at any moment will be the answer
// Time Complexity O(nlogn)+O(n+nlogM) Space Complexity O(2n+M) where M is the minimum no of platforms requried and 
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
       int n=arr.size();
       struct comp{
           bool operator()(const pair<int,int>& a,const pair<int,int>& b){
               return a.second>b.second;
           }
       };
       priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
       
       vector<pair<int,int>> ans;
       for(int i=0;i<n;i++){
           ans.push_back({arr[i],dep[i]});
       }
       sort(ans.begin(),ans.end());
       pq.push(ans[0]);
       int maxCount=1;
       for(int i=1;i<n;i++){
           int arrival=ans[i].first;
           int departure=ans[i].second;
           while(!pq.empty() && pq.top().second < arrival){  // if any trains have left before this train arrived 
               pq.pop();
           }
           pq.push({ans[i]});
           maxCount=max(maxCount,(int)pq.size()); // how many trains in the station
       }
    
       return maxCount;
    }
};


// The optimal solution by striver
// Time Complexity O(nlogn)+O(2n) Space Complexity O(1)

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0;
        int j=0;
        int n=arr.size();
        int count=0;
        int maxCount=0;
        while(i<n){
            if(arr[i]<=dep[j]){
                count++;
                i++;
            }
            else {
                count--;
                j++;
            }
            maxCount=max(maxCount,count);
        }
        return maxCount;
    }
};

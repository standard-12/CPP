#include<bits/stdc++.h>
using namespace std;

// Time Complexity O(N+NlogN+K) Space Complexity O(2N+K)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto& it:mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty() && k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};

// More Optimal ( Bucket Sorting )
// Time Complexity O(3N) Space Complexity O(2N+K)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        // priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        unordered_map<int,vector<int>> bucket;
        for(auto& it:mp){
            bucket[it.second].push_back(it.first);
        }
        int maxFreq=n;
        for(int i=n;i>0;i--){
            if(bucket.count(i)){
                for(int j=0;j<bucket[i].size();j++){
                    ans.push_back(bucket[i][j]);
                    k--;
                    if(k==0) break;
                }
            }
            if(k<=0) break;
        }
        return ans;
    }
};
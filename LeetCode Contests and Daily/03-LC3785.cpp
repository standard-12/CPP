#include<bits/stdc++.h>
using namespace std;

// This was a hard problem and this was my solution and it passed 1005/1008 test cases
// I was missing one thing and coulnd't come up with the solution for it
// nums=[41,18,19,38,38,19] forbidden = [22,39,19,7,39,19]  here both forbidded values are 19 so i can't do swaps/2+1
// (like i did in below solution)

class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n=nums.size();
        unordered_map<int,int> mp;
        unordered_map<int,int> forbid;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp.count(forbidden[i])){
                forbid[forbidden[i]]++;
            }
        }

        for(auto& it:mp){
            int key=it.first;
            int freq=it.second;
            if(forbid.count(key)){
                if(freq>n-forbid[key]) return -1;
            }
        }

        int swaps=0;
        for(int i=0;i<n;i++){
            if(nums[i]==forbidden[i]){ 
                  swaps++;  
            } 
        }
        if(swaps%2==0) return swaps/2;
        else return swaps/2+1;
    }
};


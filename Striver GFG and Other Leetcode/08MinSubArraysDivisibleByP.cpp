#include<bits/stdc++.h>
using namespace std;

// This was actually easy but a slightly differet concept similar to prefix matchings but we first 
// calulate whole sum and find target from there
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long long sum=0;
        for(int num:nums) sum+=num;
        int target=sum%p;
        if(target==0) return 0;

        unordered_map<int,int> mp;
        mp[0]=-1;
        int minDist=n; // Max it can be n
        long long  prefSum=0;
        for(int i=0;i<n;i++){
            prefSum=(prefSum+nums[i])%p;
            int want=(prefSum-target)%p;
            if(want<0) want+=p;
            if(mp.count(want)){
                minDist=min(minDist,i-mp[want]);
            }
            mp[(int)prefSum]=i;
        }    
        return minDist==n? -1:minDist;
    }
};  
#include<bits/stdc++.h>
using namespace std;

// I couldn't solve this on my own i was just learning DP at this time

// The recursive solution 
class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=rec(nums,target,0,0); // Get the max len subset which is equal to target  
        if(ans==-1) return -1;
        return n-ans;
    }

    int rec(vector<int>& nums,int target,int i,int x){
        if(i>=nums.size()){
            if(x==target) return 0;
            return -1;
        }
        int take=rec(nums,target,i+1,x^nums[i]);
        if(take!=-1)  take++; // Since we take it 
        int nontake=rec(nums,target,i+1,x);
        return max(take,nontake);
    }
};

// We can't memoize this using vector since the array elements are too large so it'll give TLE or MLE

// Actually we can use vector with size 16384 since the values are in b/w 10^4 (approxe 2^14) 
// Bitwise doesn't grow like normal sum so it will be in b/w this

// So using unordered_map<int,unordered_map<int,int>> dp
class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,unordered_map<int,int>> dp;
        int ans=rec(nums,target,0,0,dp); // Get the max len subset which is equal to target  
        if(ans==-1) return -1;
        return n-ans; // Remove the max elements possible
    }

    int rec(vector<int>& nums,int target,int i,int x,unordered_map<int,unordered_map<int,int>>& dp){
        if(i>=nums.size()){
            if(x==target) return 0;
            return -1;
        }
        if(dp.count(i) && dp[i].count(x)) return dp[i][x];
        int take=rec(nums,target,i+1,x^nums[i],dp);
        if(take!=-1)  take++; // Since we take it 
        int nontake=rec(nums,target,i+1,x,dp);
        return dp[i][x]=max(take,nontake);
    }
};

// Tabulation Solution 
class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();
        int MAXX=16384;
        vector<int> dp(MAXX,-1e9);
        
        dp[0]=0;

        for(int num:nums){
            vector<int> copy=dp;
            for(int i=0;i<MAXX;i++){
                if(dp[i]<0) continue;
                
                copy[i^num]=max(copy[i^num],dp[i]+1);
            }
            dp=copy;
        }

        return dp[target]<0? -1:n-dp[target];
    }
};

// The NON DP Solution and here there is a nice idea of dividing the array into 2 parts so that it won't give TLE 
// And makes use of a xor property a^b=target => target^a=b

class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();
        int mid=n/2;
        vector<int> left(nums.begin(),nums.begin()+mid);
        vector<int> right(nums.begin()+mid,nums.end());

        unordered_map<int,int> lmp;
        unordered_map<int,int> rmp;

        build(left,0,0,0,lmp);
        build(right,0,0,0,rmp);

        int ans=-1;
        for(auto& it:lmp){
            int val=it.first;
            int len=it.second;
            int need=val^target; // a^b=c => b^c=a => c^a=b

            if(rmp.count(need)){
                ans=max(ans,len+rmp[need]);
            }
        }
        if(ans==-1) return -1;
        return n-ans;
    }

    void build(vector<int>& nums,int i,int cnt,int xorSum,unordered_map<int,int>& mp){
        if(i>=nums.size()){
            mp[xorSum]=max(mp[xorSum],cnt);
            return ;
        }

        build(nums,i+1,cnt+1,xorSum^nums[i],mp); // Take
        build(nums,i+1,cnt,xorSum,mp); // Non take
    }
};
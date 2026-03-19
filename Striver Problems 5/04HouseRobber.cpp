#include<bits/stdc++.h>
using namespace std;

// This was my first solution Time Complexity O(n^2) + Space Complexity O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums);
        dp[0]=nums[0];
        int maxi=dp[0];
        for(int i=1;i<n;i++){
            for(int j=i-2;j>=0;j--){
                dp[i]=max(dp[i],nums[i]+dp[j]);
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};
// This was my DP solution but it's not the standar solution 
// This is correct though
// This is my second solution Time Complexity O(n) + Space Complexity O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int v1=dp[i-1]-nums[i-1]; // dp[i-1] has the maximum till [i-1] including house i-1 
            // may be it shoudn't include house[i-1] but it has so remove it i.e do -nums[i-1]
            int v2=INT_MIN;
            if(i-2>=0)v2=dp[i-2]; // Directly take i-2 because it's okay to take it 
            dp[i]=max(v1+nums[i],v2+nums[i]); // Force the current house (the current house might be in answer or not but for now force it will be removed by next one if not needed)
        }
        return n>=2? max(dp[n-1],dp[n-2]):nums[0];
    }
};

// This is my third solution Time Complexity O(n) + Space Compelxity O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int oneBehind=nums[0]; // In place of dp[i-1]
        int twoBehind=INT_MIN;
        for(int i=1;i<n;i++){
            int v1=oneBehind-nums[i-1];
            int v2=twoBehind;
            int current=max(v1+nums[i],v2+nums[i]);
            twoBehind=i-2>=0? oneBehind:nums[0];
            oneBehind=current;
        }
        return n>=2? max(twoBehind,oneBehind):nums[0];
    }
};


// I didn't try recursion but i think i wouldn't be able to come up with this

class Solution {
public:
    int rob(vector<int>& nums) {
        return rec(nums,nums.size()-1);
    }
    int rec(vector<int>& nums,int ind){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        int pick=nums[ind]+rec(nums,ind-2);
        int nonPick=rec(nums,ind-1);
        return max(pick,nonPick);
    }
};

// This is the memoized version idk why i wrote directly tabular 

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return rec(nums,nums.size()-1,dp);
    }
    int rec(vector<int>& nums,int ind,vector<int>& dp){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int pick=nums[ind]+rec(nums,ind-2,dp);
        int nonPick=rec(nums,ind-1,dp);
        return dp[ind]=max(pick,nonPick);
    }
};

// The standard Tabulated Version
// Mine was correct but not so intuitive may be
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int take = nums[i] + (i-2>=0? dp[i-2]:0);
            int nonTake = dp[i-1];
            dp[i]=max(take,nonTake);
        }
        return dp[n-1];
    }
};
#include<bits/stdc++.h>
using namespace std;

// I had done this below recursion solution 
// But i didn't realise this quesiton is same as 18CountParitionEqualsDiff until striver said
// Actually it is hard to convert this directly into Tabulation
// Tabulation is simple in the SubsetSum Problem i.e the 18th one 
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,unordered_map<int,int>> dp;
        return rec(nums,n-1,target,dp);
    }

    int rec(vector<int>& nums,int i,int target,unordered_map<int,unordered_map<int,int>>& dp){
        if(i==0){
            if(target==0 && nums[0]==0) return 2;
            if(nums[0]==abs(target)) return 1;
            return 0;
        }
        if(dp.count(i) && dp[i].count(target)) return dp[i][target];
        int plus=rec(nums,i-1,target+nums[i],dp);
        int neg=rec(nums,i-1,target-nums[i],dp);
        return dp[i][target]=plus+neg;
    }
};


// This is the same subset sum method DP i tried to write it on my own i could write correct DP for count of subsets but couldn't handle
// the negative target sum here tagret range is between [-1000,1000] 
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int num:nums) sum+=num;
        if ((sum + target) % 2 != 0 || abs(target) > sum) return 0; // This and the next line i couldn't come up this was from ChatGPT
        int newtarget = (sum + target) / 2;  // I was trying the below 2 lines basically i missed the abs(target) > sum condition
        // if(abs(sum+target)%2==1) return 0;
        // int newtarget=min(abs(sum+target)/2,abs(sum-target)/2);  
        vector<vector<int>> dp(n,vector<int>(newtarget+1,0));
        if(nums[0]==0) dp[0][0]=2;
        else dp[0][0]=1;

        if(nums[0]!=0 && nums[0]<=newtarget) dp[0][nums[0]]=1;

        for(int i=1;i<n;i++){
            for(int t=0;t<=newtarget;t++){
                int take=0;
                if(nums[i]<=t) take=dp[i-1][t-nums[i]];
                int nontake=dp[i-1][t];
                dp[i][t]=take+nontake;
            }
        }
        return dp[n-1][newtarget];
    }
};
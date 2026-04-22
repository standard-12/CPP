#include<bits/stdc++.h>
using namespace std;

// This was my code but this is brute recursion code not dp

class Solution {
public:
    bool canPartition(vector<int>& nums) {
      return rec(0,nums,0,0);  
    }

    bool rec(int ind,vector<int>& nums,int sum1,int sum2){
        if(ind==nums.size() && sum1==sum2) return true;
        if(ind>=nums.size()) return false;
        if(rec(ind+1,nums,sum1+nums[ind],sum2)) return true;
        if(rec(ind+1,nums,sum1,sum2+nums[ind])) return true;
        return false;
    }
};

// I didn't do DP for above instead i realised i could directly find the solution using the exact method of previous question 
// but just with target as sum/2 instead of sum (because the questions asks for equal sum partition)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(sum%2==1) return false;
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        int ans=rec(0,nums,0,dp,sum/2);
        return ans==1;
    }

    int rec(int ind,vector<int>& nums,int sum,vector<vector<int>>& dp,int target){
       if(sum==target) return 1;
       if(ind>=nums.size() || sum>target) return 0;
       if(dp[ind][sum]!= -1) return dp[ind][sum];
       int val=nums[ind]; 
       int take=rec(ind+1,nums,sum+val,dp,target);
       int nontake=rec(ind+1,nums,sum,dp,target);
       return dp[ind][sum]=max(take,nontake);
    }
};

// Using tabulation

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        
        int n=nums.size();
        int target=sum/2;
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));

        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=target) dp[0][nums[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool take=false;
                if(j-nums[i]>=0) take=dp[i-1][j-nums[i]];
                
                bool nontake=dp[i-1][j];

                dp[i][j]=take || nontake;
            }
        }
        return dp[n-1][target];
    }
};

// This is with 1D DP Fully Space Optimized Version

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        
        int n=nums.size();
        int target=sum/2;
        vector<bool> dp(target+1,false);

        dp[0]=true;
        
        for(int i=0;i<n;i++){
            for(int j=target;j>=0;j--){
                if(!dp[j]) continue;
                if(j+nums[i]>target) continue;
                dp[j+nums[i]]=true;
            }
        }
        return dp[target];
    }
};

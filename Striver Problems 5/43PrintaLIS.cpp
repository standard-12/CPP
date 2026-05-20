#include<bits/stdc++.h>
using namespace std;

// This was my answer using the 2D DP but we found it on our own 
class Solution {
  public:
    vector<int> getLIS(vector<int>& nums) {
        // Code here
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int opt1=0,opt2=0;
                if(prev==-1 || nums[i]>nums[prev]){
                    opt1=1+dp[i+1][i+1];
                }
                opt2=dp[i+1][prev+1];
                dp[i][prev+1]=max(opt1,opt2);
            }
        }
        vector<int> ans;
        int i=0,j=0;
        while(i<n && j<n){
            if(dp[i][j]==1+dp[i+1][i+1]){
                ans.push_back(nums[i]);
                i=i+1;
                j=i;
            }
            else {
                i=i+1;
            }
        }
        return ans;
    }
};

// 
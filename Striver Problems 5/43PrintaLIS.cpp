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

// This is O(n) space Solution of Striver with hash array

class Solution {
  public:
    vector<int> getLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),hash(n,0);
        int maxi=1,maxInd=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(1+dp[j]>dp[i]){
                        hash[i]=j;
                        dp[i]=1+dp[j];
                    }
                }   
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                maxInd=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[maxInd]);
        while(hash[maxInd]!=maxInd){
            maxInd=hash[maxInd];
            ans.push_back(nums[maxInd]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
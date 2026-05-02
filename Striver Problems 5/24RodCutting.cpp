#include<bits/stdc++.h>
using namespace std;

// I wrote this on my own and it was similar to previous problems 
class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return rec(price,n-1,n,dp);
    }
    
    int rec(vector<int>& price,int i,int totalLength,vector<vector<int>>& dp){
        if(totalLength==0) return 0;
        if(i==0){
            // At i==0 the length is 1 so we can return len*val[0];
            return totalLength*price[0];
        }
        if(dp[i][totalLength]!=-1) return dp[i][totalLength];
        int take=0;
        if(i+1<=totalLength) take=price[i]+rec(price,i,totalLength-(i+1),dp);
        int nontake=rec(price,i-1,totalLength,dp);
        return dp[i][totalLength]=max(take,nontake);
    }
};

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=i*price[0];
        }
        
        for(int i=1;i<n;i++){
            for(int l=1;l<=n;l++){
                int take=0;
                if(i+1<=l) take=price[i]+dp[i][l-(i+1)];
                int nontake=dp[i-1][l];
                dp[i][l]=max(take,nontake);
            }
        }
        return dp[n-1][n];
    }
};

// Space Optimized DP

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<int> dp(n+1,0);
        for(int i=0;i<=n;i++){
            dp[i]=i*price[0];
        }
        
        for(int i=1;i<n;i++){
            for(int l=1;l<=n;l++){
                int take=0;
                if(i+1<=l) take=price[i]+dp[l-(i+1)];
                int nontake=dp[l];
                dp[l]=max(take,nontake);
            }
        }
        return dp[n];
    }
};
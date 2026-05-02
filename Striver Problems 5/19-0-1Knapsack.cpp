#include<bits/stdc++.h>
using namespace std;

// I wrote recursion on my own but strugglead a lil bit with tabulation
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return rec(val,wt,n-1,W,dp);
    }
    
    int rec(vector<int>& val,vector<int>& weights,int i,int W,vector<vector<int>>& dp){
        if(i==0 || W==0){
            if(weights[0]<=W) return val[0];
            return 0;
        }
        if(dp[i][W]!=-1) return dp[i][W];
        int take=0,nontake=0;
        if(weights[i]<=W) take=val[i]+rec(val,weights,i-1,W-weights[i],dp);
        nontake=rec(val,weights,i-1,W,dp);
        return dp[i][W]=max(take,nontake);
    }
};

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        for(int j=wt[0];j<=W;j++) dp[0][j]=val[0];
    
        for(int i=1;i<n;i++){
            for(int j=0;j<=W;j++){
                int take=0,nontake=0;
                if(wt[i]<=j) take=val[i]+dp[i-1][j-wt[i]];
                nontake=dp[i-1][j];
                dp[i][j]=max(take,nontake);
            }        
        }
        return dp[n-1][W];
    }
    
};


// We can easily optimize above to 2 row dp but we can also optimize it to 1 row dp as below
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        vector<int> dp(n,0);
        for(int j=wt[0];j<=W;j++) dp[j]=val[0];
    
        for(int i=1;i<n;i++){
            for(int j=W;j>=0;j--){ // Opposite direction
                int take=0,nontake=0;
                if(wt[i]<=j) take=val[i]+dp[j-wt[i]];
                nontake=dp[j];
                dp[j]=max(take,nontake);
            }        
        }
        return dp[W];
    }   
};

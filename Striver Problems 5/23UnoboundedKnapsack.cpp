#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return rec(val,wt,n-1,capacity,dp);
    }
    
    int rec(vector<int>& val,vector<int>& wt,int i,int capac,vector<vector<int>> &dp){
        if(capac==0) return 0;
        if(i==0){
            if(wt[0]<=capac){
                int cnt=capac/wt[0];
                return cnt*val[0];
            }
            return 0;
        }
        if(dp[i][capac]!=-1) return dp[i][capac];
        int take=INT_MIN;
        if(wt[i]<=capac) take=val[i]+rec(val,wt,i,capac-wt[i],dp);
        int nontake=rec(val,wt,i-1,capac,dp);
        return dp[i][capac]=max(take,nontake);
    }
};

// I wrote this tabulation from the above code like how striver does 
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,0));
        for(int w=0;w<=capacity;w++){  // the recursion base cases will be put here
            if(wt[0]<=w) {
                int cnt=w/wt[0];
                dp[0][w]=cnt*val[0];
            }
        }
        
        for(int i=1;i<n;i++){
            for(int w=0;w<=capacity;w++){ 
                int take=INT_MIN;
                if(wt[i]<=w) take=val[i]+dp[i][w-wt[i]]; // replace recusion states with dp 
                int nontake=dp[i-1][w];
                dp[i][w]=max(take,nontake);
            }
        }
        return dp[n-1][capacity];
    }
    
};
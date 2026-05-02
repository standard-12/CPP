#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return rec(coins,n-1,amount,dp);
    }
    int rec(vector<int>& coins,int i,int amount,vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(i==0){
            if(amount%coins[0]==0) return 1;
            return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=0;
        if(coins[i]<=amount) take=rec(coins,i,amount-coins[i],dp);
        int nontake=rec(coins,i-1,amount,dp);
        return dp[i][amount]=take+nontake;
    }
};

// Tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned int>> dp(n,vector<unsigned int>(amount+1,0));
        dp[0][0]=1; 
        for(int a=1;a<=amount;a++) if(a%coins[0]==0) dp[0][a]=1;
        
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                    unsigned int take=0;
                    if(coins[i]<=a) take=dp[i][a-coins[i]];
                    unsigned int nontake=dp[i-1][a];
                    dp[i][a]=take+nontake;
            }
        }
        return dp[n-1][amount];
    }
};
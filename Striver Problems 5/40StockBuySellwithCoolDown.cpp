#include<bits/stdc++.h>
using namespace std;

// This is the memoized solution 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return rec(prices,0,1,dp);
    }

    int rec(vector<int>& prices,int i,int canBuy,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][canBuy]!= -1) return dp[i][canBuy];
        if(canBuy){
            int buy=-prices[i]+rec(prices,i+1,0,dp);
            int skip=rec(prices,i+1,canBuy,dp);
            return dp[i][canBuy]=max(buy,skip);
        }
        else {
            int sell=prices[i]+rec(prices,i+2,1,dp);
            int hold=rec(prices,i+1,canBuy,dp);
            return dp[i][canBuy]=max(sell,hold);
        }
    }
};

// Tabulation 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            dp[i][1]= max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            dp[i][0]= max(prices[i]+dp[i+2][1],dp[i+1][0]);
        }
        return dp[0][1];
    }

};
#include<bits/stdc++.h>
using namespace std;

// Recursion 
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return rec(prices,0,1,fee,dp);
    }

    int rec(vector<int>& prices,int i,int canBuy,int fee,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][canBuy]!= -1) return dp[i][canBuy];
        if(canBuy){
            int buy=-prices[i]+rec(prices,i+1,0,fee,dp);
            int skip=rec(prices,i+1,canBuy,fee,dp);
            return dp[i][canBuy]=max(buy,skip);
        }
        else {
            int sell=(prices[i]-fee)+rec(prices,i+1,1,fee,dp);
            int hold=rec(prices,i+1,canBuy,fee,dp);
            return dp[i][canBuy]=max(sell,hold);
        }
    }
};

// The Space Optimized Tabulation directly
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> curr(2,0),ahead(2,0);
        for(int i=n-1;i>=0;i--){
            curr[1]= max(-prices[i]+ahead[0],ahead[1]);
            curr[0]= max(prices[i]-fee+ahead[1],ahead[0]);
            ahead=curr;
        }
        return ahead[1];
    }
};
#include<bits/stdc++.h>
using namespace std;

// This can be solved without recursion or DP as follows
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                int profit=prices[i]-prices[i-1];
                maxprofit+=profit;
            }
        }
        return maxprofit;
    }
};

// This is the actual DP method with recursion + memoization
// I couldn't come up with this i was sending buyValue with the recursion but this uses "-prices[i]" very clevelrly to overcome state problems(because if we consider buy value as state it doesn't have any benefit also the buyvalue range is more )
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return rec(prices,0,true,dp);
    }

    int rec(vector<int>& prices,int i,int canBuy,vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        int buyInd= canBuy? 1:0;
        if(dp[i][buyInd]!=-1) return dp[i][buyInd];
        if(canBuy){
            int buy = -prices[i]+rec(prices,i+1,false,dp); // Buy now
            int skip = rec(prices,i+1,canBuy,dp); // Buy later ( canBUy is true we can pass true also in rec instead of canBuy)
            return dp[i][buyInd]=max(buy,skip);
        }
        else {
            int sell = prices[i]+rec(prices,i+1,true,dp); // Sell now
            int hold = rec(prices,i+1,canBuy,dp); // Sell later
            return dp[i][buyInd]=max(sell,hold);
        }

    }
};

// Tabulated Version
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==1) { // CanBuy case
                    dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                } 
                else {
                    dp[i][j]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

// Space Optimized Version
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> curr(2,0),ahead(2,0);
        ahead[0]=0;
        ahead[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==1) { // CanBuy case
                    curr[j]=max(-prices[i]+ahead[0],ahead[1]);
                } 
                else {
                    curr[j]=max(prices[i]+ahead[1],ahead[0]);
                }
            }
            ahead=curr;
        }
        return ahead[1];
    }
};

// We can even replace it with variables and no if-else and all needed 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> curr(2,0),ahead(2,0);
        ahead[0]=0;
        ahead[1]=0;
        for(int i=n-1;i>=0;i--){
            curr[1]=max(-prices[i]+ahead[0],ahead[1]);
            curr[0]=max(prices[i]+ahead[1],ahead[0]);
            ahead=curr;
        }
        return ahead[1];
    }
};
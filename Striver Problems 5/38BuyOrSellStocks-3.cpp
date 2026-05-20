#include<bits/stdc++.h>
using namespace std;

// I solved it on my own 

// My first memoized solution 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2,-1)));
        return rec(prices,0,2,1,dp);
    }

    int rec(vector<int>& prices,int i,int canBuy,int sold,vector<vector<vector<int>>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][canBuy][sold]!=-1) return dp[i][canBuy][sold];
        if(canBuy>0 && sold==1){
            int buy=-prices[i]+rec(prices,i+1,canBuy-1,0,dp);
            int skip=rec(prices,i+1,canBuy,sold,dp);
            return dp[i][canBuy][sold]=max(buy,skip);
        }
        else if(sold==0){
            int sell=prices[i]+rec(prices,i+1,canBuy,1,dp);
            int hold=rec(prices,i+1,canBuy,sold,dp);
            return dp[i][canBuy][sold]=max(sell,hold);
        }
        return 0;
    }

};

// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(2,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=2;j++){
                for(int k=0;k<=1;k++){
                    int canBuy=j;
                    int sold=k;
                    if(canBuy>0 && sold==1){
                        int buy=-prices[i]+dp[i+1][canBuy-1][0];
                        int skip=dp[i+1][canBuy][sold];
                        dp[i][canBuy][sold]=max(buy,skip);
                    }
                    else if(sold==0){
                        int sell=prices[i]+dp[i+1][canBuy][1];
                        int hold=dp[i+1][canBuy][sold];
                        dp[i][canBuy][sold]=max(sell,hold);
                    }
                }
            }
        }
        return dp[0][2][1];
    }
};

// Space Optimization-1

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> curr(3,vector<int>(2,0)),ahead(3,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=2;j++){
                for(int k=0;k<=1;k++){
                    int canBuy=j;
                    int sold=k;
                    if(canBuy>0 && sold==1){
                        int buy=-prices[i]+ahead[canBuy-1][0];
                        int skip=ahead[canBuy][sold];
                        curr[canBuy][sold]=max(buy,skip);
                    }
                    else if(sold==0){
                        int sell=prices[i]+ahead[canBuy][1];
                        int hold=ahead[canBuy][sold];
                        curr[canBuy][sold]=max(sell,hold);
                    }
                    ahead=curr;
                }
            }
        }
        return ahead[2][1];
    }
};

// Space optimization-2 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> curr(3,vector<int>(2,0));

        for(int i=n-1;i>=0;i--){
            for(int j=2;j>=0;j--){
                for(int k=0;k<=1;k++){
                    int canBuy=j;
                    int sold=k;
                    if(canBuy>0 && sold==1){
                        int buy=-prices[i]+curr[canBuy-1][0];
                        int skip=curr[canBuy][sold];
                        curr[canBuy][sold]=max(buy,skip);
                    }
                    else if(sold==0){
                        int sell=prices[i]+curr[canBuy][1];
                        int hold=curr[canBuy][sold];
                        curr[canBuy][sold]=max(sell,hold);
                    }
                }
            }
        }
        return curr[2][1];
    }
};

// This is another solution with n*4 space complexity
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return rec(prices,0,0,dp);
    }

    int rec(vector<int>& prices,int i,int trans,vector<vector<int>>& dp){
        if(i==prices.size() || trans==4) return 0;
        if(dp[i][trans]!=-1) return dp[i][trans];

        if(trans%2==0){
            int opt1= -prices[i] + rec(prices,i+1,trans+1,dp);
            int opt2=rec(prices,i+1,trans,dp);
            return dp[i][trans]=max(opt1,opt2);
        }
        else {
            int opt1=prices[i] + rec(prices,i+1,trans+1,dp);
            int opt2=rec(prices,i+1,trans,dp);
            return dp[i][trans]=max(opt1,opt2);
        }

    }
};

// Till Space optimizaiton-2 i only figured out the last space optimization is actually crazy i coulnd't come up with that
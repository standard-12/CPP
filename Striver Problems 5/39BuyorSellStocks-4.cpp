#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
        return rec(prices,0,0,dp,k);
    }

    int rec(vector<int>& prices,int i,int trans,vector<vector<int>>& dp,int k){
        if(i==prices.size() || trans==2*k) return 0;
        if(dp[i][trans]!=-1) return dp[i][trans];
        if(trans%2==0){
            int opt1=-prices[i]+rec(prices,i+1,trans+1,dp,k);
            int opt2=rec(prices,i+1,trans,dp,k);
            return dp[i][trans]=max(opt1,opt2);
        }
        else {
            int opt1=prices[i]+rec(prices,i+1,trans+1,dp,k);
            int opt2=rec(prices,i+1,trans,dp,k);
            return dp[i][trans]=max(opt1,opt2);
        }
    }
};


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
        return rec(prices,0,2*k,dp);
    }

    int rec(vector<int>& prices,int i,int trans,vector<vector<int>>& dp){
        if(i==prices.size() || trans==0) return 0;
        if(dp[i][trans-1]!=-1) return dp[i][trans-1];
        if(trans%2==0){
            int opt1=-prices[i]+rec(prices,i+1,trans-1,dp);
            int opt2=rec(prices,i+1,trans,dp);
            return dp[i][trans-1]=max(opt1,opt2);
        }
        else {
            int opt1=prices[i]+rec(prices,i+1,trans-1,dp);
            int opt2=rec(prices,i+1,trans,dp);
            return dp[i][trans-1]=max(opt1,opt2);
        }
    }
};

// I wrote tabulation for 2nd solution of memo not first one 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=2*k;j++){
                if(j%2==0){
                    int opt1=-prices[i]+dp[i+1][j-1];
                    int opt2=dp[i+1][j];
                    dp[i][j]=max(opt1,opt2);
                }
                else {
                    int opt1=prices[i]+dp[i+1][j-1];
                    int opt2=dp[i+1][j];
                    dp[i][j]=max(opt1,opt2);                    
                }
            }
        }
        return dp[0][2*k];
    }
};
#include<bits/stdc++.h>
using namespace std;

// The brute recursion Time Complexity >>O(2^n) (Because repeated takes are allowed)
// Space Complexity O(target) because if a coin is 1 then it will go depth equal to target 

// This was my solution but there was one unnecessary recursion call
// Time Complexity O(n*target)
// Space Complexity O(n*target)+O(target)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1)); 
        int ans=rec(coins,n-1,amount,dp);
        return ans>=1e5? -1:ans;
    }

    int rec(vector<int>& coins,int i,int amount,vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(i==0 ){
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e5;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=INT_MAX,nontake=INT_MAX;
        if(coins[i]<=amount) take=1+min( rec(coins,i-1,amount-coins[i],dp) , rec(coins,i,amount-coins[i],dp) ); 
        // This was inefficient actually we could just do take=1+rec(coins,i,amount-coins[i],dp); 
        // because this internally calls rec(coins,i-1,amount-coins[i],dp)  in non take part 
        nontake=rec(coins,i-1,amount,dp);
        return dp[i][amount]=min(take,nontake);
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,1e5)); 
        if(amount==0) return 0;
        for(int a=0;a<=amount;a++) {
            if(a%coins[0]==0) dp[0][a]=a/coins[0];
        }
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                int take=INT_MAX,nontake=INT_MAX;
                if(coins[i]<=a) take=1+min( dp[i-1][a-coins[i]],dp[i][a-coins[i]] ); // Same here also the 2 dp states were not required
                // only dp[i][a-counts[i]] was enough
                nontake=dp[i-1][a];
                dp[i][a]=min(take,nontake);
            }
        }
        return dp[n-1][amount]>=1e5? -1:dp[n-1][amount];
    }
};

// This is 1 row optimized dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,1e5);
        if(amount==0) return 0;
        for(int a=0;a<=amount;a++) {
            if(a%coins[0]==0) dp[a]=a/coins[0];
        }
        dp[0]=0; // this is needed and also here we don't do reverse traverse for 1 row dp 
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                int take=INT_MAX,nontake=INT_MAX;
                if(coins[i]<=a) take=1+dp[a-coins[i]];
                nontake=dp[a];
                dp[a]=min(take,nontake);
            }
        }
        return dp[amount]>=1e5? -1:dp[amount];
    }
};
// For test case [1,2,5] target=11 
// Initially dp will be [0,1,2,3,4,5,6,7,8,9,10,11]
// after i=1 (coin=2)   [0,1,1,2,2,3,3,4,4,5,5 , 6]
// after i=2 (coin=5)   [0,1,1,2,2,1,2,2,3,3,2 , 3]
// And ans is dp[11] which is 3


// We can do another thing with switching for loop order
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e5);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int coin : coins){
                if(coin<=i) dp[i]=min(dp[i],1+dp[i-coin]);
            }
        }
        return dp[amount]>=1e5? -1:dp[amount];
    }
};

// Here for [1,2,5] 11
// initially [0,1e5,1e5,.....]
// i=1       [0,1,1e5,1e5,...]
// i=2       [0,1,2,1e5,1e5,....]
// i=3       [0,1,2,2,1e5,1e5,....]
// ......
// i=11      [0,1,1,2,2,1,2,2,3,3,2 , 3]
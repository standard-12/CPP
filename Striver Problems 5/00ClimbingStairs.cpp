#include<bits/stdc++.h>
using namespace std;

// The recursive solution gives TLE
// Time Complexity O(2^n) + Space Complexity O(n) (Recursion Stack)
class Solution {
public:
    int climbStairs(int n) {
        return rec(n);
    }
    int rec(int n){
        if(n==1) return 1;
        if(n==2) return 2;
        
        return rec(n-1)+rec(n-2);
    }
};

// Solution using Memoization
// Time Complexity O(n) Space Complexity O(n)(Memo Vector)+O(n)(Recursion)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        return rec(n,memo);   
    }
    int rec(int n,vector<int>& memo){
        if(n==1) return 1;
        if(n==2) return 2;
        if(memo[n]!=-1) return memo[n];
        memo[n]=rec(n-1,memo)+rec(n-2,memo);
        return memo[n];
    }
};

// Solution using Tabulation
// Time Complexity O(n) + Space Complexity O(n)

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        if(n==1) return 1; 
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

// Solution using Space Optimized DP
// TIme Complexity O(n) Space Complexity O(1)

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1; 
        int a=1; // From last solution we got to know that we need only the last 2 
        int b=2; // values to compute so store it in variable instead of a vector
        for(int i=3;i<=n;i++){
            int c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
};
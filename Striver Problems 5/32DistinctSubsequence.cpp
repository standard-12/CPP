#include<bits/stdc++.h>
using namespace std;

// The memoization version it gave TLE
class Solution {
public:
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return rec(s,t,n1-1,n2-1,dp);
    }

    int rec(string s,string t,int i,int j,vector<vector<int>>& dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0,nontake=0;
        if(s[i]==t[j]){
            take=rec(s,t,i-1,j-1,dp);
        }
        nontake=rec(s,t,i-1,j,dp);
        return dp[i][j]=take+nontake;
    }
};
// Tabulation 
class Solution {
public:
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector<vector<unsigned int>> dp(n1+1,vector<unsigned int>(n2+1,0)); // index shifting
        for(int i=0;i<n1;i++) dp[i][0]=1; // i.e for any value of i but j should be zero (base case i.e in recursion j<0) 
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                unsigned int take=0,nontake=0;
                if(s[i-1]==t[j-1]) take=dp[i-1][j-1];
                nontake=dp[i-1][j];
                dp[i][j]=take+nontake;
            }
        }
        return dp[n1][n2];
    }
};
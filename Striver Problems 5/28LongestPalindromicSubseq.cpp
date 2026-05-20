#include<bits/stdc++.h>
using namespace std;

// This was my recursive solution 
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        vector<int> curr(n+1,0),prev(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++ ){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else {
                    curr[j]=max(curr[j-1],prev[j]);
                }
            }
             prev=curr;
        }
        return prev[n];
    }
};

// This can be solved using LCS with reversing the string and doing the exact same as LCS

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++ ){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};

// Space optimized

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        vector<int> curr(n+1,0),prev(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++ ){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else {
                    curr[j]=max(curr[j-1],prev[j]);
                }
            }
             prev=curr;
        }
        return prev[n];
    }
};

// The my original recursive solution's Tabulation Looks something like this

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case: single characters
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // length of substring
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            if(s[i] == s[j]) {
                dp[i][j] = 2 + (i+1 <= j-1 ? dp[i+1][j-1] : 0);
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[0][n-1];
}

// for s="bbbab"

// dp array will be 
// 1 2 3 3 4 
// 0 1 2 2 3 
// 0 0 1 1 3 
// 0 0 0 1 1 
// 0 0 0 0 1 
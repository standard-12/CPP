#include<bits/stdc++.h>
using namespace std;

// I solved it on my own and here i used i==0 || j==0 as base case so it will be easy to convert to tabulation but striver 
// used index shifitng for tabulation and kept the recursion clean (i.e base case is i<0 || j<0)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return rec(text1,text2,n1-1,n2-1,dp);
    }
    int rec(string& s1,string& s2,int i,int j ,vector<vector<int>>& dp){
        if(i==0 || j==0) {  
            if(i==0){
                for(int k=j;k>=0;k--) if(s1[i]==s2[k]) return 1; 
            }
            else {
                for(int k=i;k>=0;k--) if(s1[k]==s2[j]) return 1;
            }
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int opt1=0,opt2=0,opt3=0;
        if(s1[i]==s2[j]){
            opt1=1+rec(s1,s2,i-1,j-1,dp); // If both are same we can directly take it
        }
        else {
            // opt1=rec(s1,s2,i-1,j-1); // THis is not need this will be covered in belowe cases automatically
            opt2=rec(s1,s2,i-1,j,dp); // Only move i
            opt3=rec(s1,s2,i,j-1,dp); // Only move j
        }
        return dp[i][j]=max(opt1,max(opt2,opt3));
    }
};
// Tabulation of my solution
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,0));
        for(int k=0;k<n2;k++) { // i.e when i==0 in recursion
            if(text1[0]==text2[k]) dp[0][k]=1;
            else if(k>0) dp[0][k]=max(0,dp[0][k-1]);
        }
        for(int k=0;k<n1;k++){ // i.e when j==0 case
            if(text1[k]==text2[0]) dp[k][0]=1;
            else if(k>0) dp[k][0]=max(0,dp[k-1][0]);
        }

        for(int i=1;i<n1;i++){
            for(int j=1;j<n2;j++){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n1-1][n2-1];
    }
};

// The cleaner recursion 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return rec(text1,text2,n1-1,n2-1,dp);
    }
    int rec(string& s1,string& s2,int i,int j ,vector<vector<int>>& dp){
        if(i<0 || j<0) {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+rec(s1,s2,i-1,j-1,dp); // If both are same we can directly take it
        }
        else {
            return dp[i][j]=max(rec(s1,s2,i-1,j,dp),rec(s1,s2,i,j-1,dp)); 
        }
    }
};

// But to convert the above to tabulation we should do index shifting i.e where dp[i][j] is there that should be dp[i-1][j-1]

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                // comparing s1[i-1]==s2[j-1] instead s1[i]==s2[j]
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};

// The space optimized DP

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>> dp(2,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]) dp[1][j]=1+dp[0][j-1];
                else dp[1][j]=max(dp[0][j],dp[1][j-1]);
            }
            dp[0]=dp[1];
        }
        return dp[0][n2];
    }
};

// Apparently it can even be optimized to 1D DP
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> dp(n2 + 1, 0);

        for (int i = 1; i <= n1; i++) {
            int prev = 0; // this represents dp[i-1][j-1]

            for (int j = 1; j <= n2; j++) {
                int temp = dp[j]; // store old dp[i-1][j]

                if (s1[i-1] == s2[j-1])
                    dp[j] = 1 + prev;
                else
                    dp[j] = max(dp[j], dp[j-1]);

                prev = temp; // move diagonal forward
            }
        }
        return dp[n2];
    }
};
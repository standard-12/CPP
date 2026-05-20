#include<bits/stdc++.h>
using namespace std;


// I solved it on my own and This is my solution but the case handling is not good it could have been done better
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return rec(word1,word2,n1-1,n2-1,dp);
    }
    int rec(string& word1,string& word2,int i,int j,vector<vector<int>>& dp){
        if(i<0 && j<0) {
            return 0;
        }
        if(i>=0 && j>=0 && dp[i][j]!=-1) return dp[i][j];
        int opt1=INT_MAX,opt2=INT_MAX,opt3=INT_MAX,opt4=INT_MAX;
        if(i>=0 && j>=0 && word1[i]==word2[j]) {
            opt1=rec(word1,word2,i-1,j-1,dp);
        }
        else {
            if(j>=0)opt2=1+rec(word1,word2,i,j-1,dp); // if not equal one operation to be performed delete jth char/insert ith char
            if(i>=0)opt3=1+rec(word1,word2,i-1,j,dp); // if not equal one operation to be performed deltete ith char/insert jth char
            if(i>=0 && j>=0) opt4=1+rec(word1,word2,i-1,j-1,dp); // replace the char
        }
        int mini=min(min(opt1,opt4),min(opt2,opt3));
        if(i<0 || j<0) return mini;
        return dp[i][j]=mini;
    }
};

// Memoization with better recursion edge case handling

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return rec(word1,word2,n1-1,n2-1,dp);
    }
    int rec(string& word1,string& word2,int i,int j,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        int opt1=INT_MAX,opt2=INT_MAX,opt3=INT_MAX,opt4=INT_MAX;
        if(word1[i]==word2[j]) {
            opt1=rec(word1,word2,i-1,j-1,dp);
        }
        else {
            opt2=1+rec(word1,word2,i,j-1,dp); // if not equal one operation to be performed delete jth char/insert ith char
            opt3=1+rec(word1,word2,i-1,j,dp); // if not equal one operation to be performed deltete ith char/insert jth char
            opt4=1+rec(word1,word2,i-1,j-1,dp); // replace the char
        }
        return dp[i][j]=min(min(opt1,opt4),min(opt2,opt3));
    }
};

// Tabulation

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++) dp[i][0]=i;
        for(int j=1;j<=n2;j++) dp[0][j]=j;
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                int opt1=INT_MAX,opt2=INT_MAX,opt3=INT_MAX,opt4=INT_MAX;
                if(word1[i-1]==word2[j-1]){
                    opt1=dp[i-1][j-1];
                }
                opt2=1+dp[i][j-1];
                opt3=1+dp[i-1][j];
                opt4=1+dp[i-1][j-1];
                dp[i][j]=min(min(opt1,opt2),min(opt3,opt4));
            }  
        }
        return dp[n1][n2];
    }
};
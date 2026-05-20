#include<bits/stdc++.h>
using namespace std;

// At last i solved on my own 
// It was bit confusing but i used to solve on my own 
// Apparently for this problem Tabulation is more direct than Recursion 
class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        int maxi=0;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(s1[i]==s2[j]) maxi=max(maxi,findSubstr(s1,s2,i,j,dp));    
            }
        }
        return maxi;
    }
    
    int findSubstr(string& s1,string& s2,int i,int j,vector<vector<int>>& dp){
        if(i>=s1.size() || j>=s2.size()) return 0;
        if(s1[i]!=s2[j]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=1+findSubstr(s1,s2,i+1,j+1,dp);
    }
};

// Tabulation
class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        int maxi=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]) maxi=max(maxi,dp[i][j]=1+dp[i-1][j-1]);  // Here compare s1[i-1]==s2[i-1] Due to index shifting
            }
        }
        return maxi;
    }
};
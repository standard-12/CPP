#include<bits/stdc++.h>
using namespace std;

// First i had made a mistake "when p[j]=='*' i was exploring rec(i-1,j) & rec(i-1,j-1) but i had to do
// rec(i-1,j) & rec(i,j-1) because '*' also included empty spaces ""  " 
class Solution {
public:
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        int ans=rec(s,p,n1-1,n2-1,dp);
       
        return ans==1? true:false;
    }

    int rec(string& s,string& p,int i,int j,vector<vector<int>>& dp){
        if(i<0 && j<0) return 1;
        if(i<0 || j<0) {
            if(i<0) {
                for(int k = 0; k <= j; k++){
                    if(p[k] != '*') return 0;
                }
                return 1;
            }
            else return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=rec(s,p,i-1,j-1,dp);
        }
        if(p[j]=='*'){
            return dp[i][j]=max(rec(s,p,i-1,j,dp),rec(s,p,i,j-1,dp));
        }
        return dp[i][j]=0;
    }
};

// Tabulation 
class Solution {
public:
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n1;i++){
            dp[i][0]=0;
        }
        bool stars=true;
        for(int j=1;j<=n2;j++){
            if(p[j-1]!='*') stars=false;
            if(stars) dp[0][j]=1;
            else dp[0][j]=0;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*') {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                else {
                    dp[i][j]=0;
                }
            }
        }
        
        return dp[n1][n2]==1? true:false;
    }
};


// Space Optimization

class Solution {
public:
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        vector<int> prev(n2+1,0),curr(n2+1,0);
        prev[0]=1;
        curr[0]=0;
        bool stars=true;
        for(int j=1;j<=n2;j++){
            if(p[j-1]!='*') stars=false;
            if(stars) prev[j]=1;
            else prev[j]=0;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    curr[j]=prev[j-1];
                }
                else if(p[j-1]=='*') {
                    curr[j]=max(prev[j],curr[j-1]);
                }
                else {
                    curr[j]=0;
                }
            }
            prev=curr;
        }
        
        return prev[n2]==1? true:false;
    }
};
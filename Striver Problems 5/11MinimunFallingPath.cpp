#include<bits/stdc++.h>
using namespace std;

// Memoized Version (Gave TLE)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int mini=INT_MAX;
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        for(int i=0;i<cols;i++){
            mini=min(mini,rec(matrix,0,i,dp));
        }
        return mini;
    }

    int rec(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>& dp){
        int m=matrix.size(); int n=matrix[0].size();
        if(row>=m || col<0 || col>=n ) return 1e9;
        if(row==m-1 && col>=0 && col<n) return matrix[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int mini=1e9;
        for(int i=col-1;i<=col+1;i++){
            mini=min(mini,rec(matrix,row+1,i,dp)); // Next row and the three columns of next row
        }
        return dp[row][col]=matrix[row][col]+mini;
    }
};

// Tabulation Version

class Solution {
public:
    int L_MAX=1e9;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();

        vector<vector<int>> dp(n,vector<int>(n,L_MAX));
        dp[0]=matrix[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int val=matrix[i][j];
                for(int k=j-1;k<=j+1;k++){
                    if(k>=0 && k<n){
                        dp[i][j]=min(dp[i][j],val+dp[i-1][k]); // Note the dp[i-1] 
                    }
                }
            }
        }   
        int ans=L_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};

// Space Optimized DP
class Solution {
public:
    int L_MAX=1e9;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1) {
            return *min_element(matrix[0].begin(),matrix[0].end()); // This is to handle cases where n==1 since i remove a separate for loop at the end this will be necessary
        }
        vector<vector<int>> dp(2,vector<int>(n,L_MAX));
        dp[0]=matrix[0];
        int ans=L_MAX;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int val=matrix[i][j];
                for(int k=j-1;k<=j+1;k++){
                    if(k>=0 && k<n){
                        dp[1][j]=min(dp[1][j],val+dp[0][k]); // Note the dp[1] && dp[0]
                    }
                }
                if(i==n-1) ans=min(ans,dp[1][j]); // Storing the ans;
            }
            dp[0]=dp[1];
            dp[1].assign(n,L_MAX);
        }   
        return ans;
    }
};
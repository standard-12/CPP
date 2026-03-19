#include<bits/stdc++.h>
using namespace std;

// This was my first solution but it gave me MLE
// Time Complexity O(9*n) Space Complexity O(9*n)
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        dp[0]=mat[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(j!=k){
                        dp[i][j]=max(dp[i][j],mat[i][j]+dp[i-1][k]);
                    }
                }
            }
        }
        return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    }
};

// Later i used constant Space vector
// Time Complexity O(9*n) Space Complexity O(1)

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<vector<int>> dp(2,vector<int>(3,0));
        dp[0]=mat[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(j!=k){
                        dp[1][j]=max(dp[1][j],mat[i][j]+dp[0][k]);
                    }
                }
            }
            dp[0]=dp[1];
            dp[1]={}; // For safety
        }
        return max(dp[1][0],max(dp[1][1],dp[1][2]));
    }
};

// Just wrote recursion just for the understanding 
// Time COmplexity O(3^n) Space Complexity O(n)
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        return rec(mat,mat.size()-1,-1);
    }
    
    int rec(vector<vector<int>>& mat,int row,int prevCol){
        if(row<0) return 0;
        int maxi=INT_MIN;
        for(int col=0;col<3;col++){
            if(col!=prevCol){
                maxi=max(maxi,mat[row][col]+rec(mat,row-1,col));
            }
        }
        return maxi;
    }
};

// Memoized Version
// Time Compelxity O(9*n) Space Complexity(9*n)

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // Some solution initialised table with size 4
        vector<vector<int>> dp(mat.size(),vector<int>(3,-1));
        // Use for loop here instead
        int v1=rec(mat,mat.size()-1,0,dp);
        int v2=rec(mat,mat.size()-1,1,dp);
        int v3=rec(mat,mat.size()-1,2,dp);
        return max(v1,max(v2,v3));
    }
    
    int rec(vector<vector<int>>& mat,int row,int prevCol,vector<vector<int>>& dp){
        if(row<0) return 0;
        if(dp[row][prevCol]!=-1) return dp[row][prevCol];
        int maxi=INT_MIN;
        for(int col=0;col<3;col++){
            if(col!=prevCol){
                maxi=max(maxi,mat[row][col]+rec(mat,row-1,col,dp));
                
            }
        }
        return dp[row][prevCol]=maxi;
    }
};

// This is a nice idea with 4 columns using last column to store the no restriction case
// Only last element in that column will be filled hence my solution is actually better

class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return rec(mat, n-1, 3, dp);  // 3 = no restriction
    }

    int rec(vector<vector<int>>& mat, int row, int prevCol, vector<vector<int>>& dp){
        if(row < 0) return 0;

        if(dp[row][prevCol] != -1) return dp[row][prevCol];

        int maxi = 0;

        for(int col = 0; col < 3; col++){
            if(col != prevCol){
                maxi = max(maxi, mat[row][col] + rec(mat, row-1, col, dp));
            }
        }

        return dp[row][prevCol] = maxi;
    }
};
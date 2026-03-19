#include<bits/stdc++.h>
using namespace std;

// Yee i wrote all the 4 solutions on my own

// The recursive solution 
// Time Complexity (2^(m*n)) Space Complexity O(m+n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        return rec(m,n);   
    }
    int rec(int row,int col){
        if(row==1 && col==1) return 1;
        if(row<1 || col<1) return 0;
        return rec(row-1,col)+rec(row,col-1);
    }
};

// Memoization 
// Time Complexity O(m*n) Space Complexity O(m*n)+O(m+n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return rec(m-1,n-1,dp);   
    }
    int rec(int row,int col,vector<vector<int>>& dp){
        if(row==0 && col==0) return 1;
        if(row<0 || col<0) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        dp[row][col]=rec(row-1,col,dp)+rec(row,col-1,dp);
        return dp[row][col];
    }
};

// Tabulation 
// Time Complexity O(m*n) Space Complexity O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row==0 && col==0) continue;
                dp[row][col]= ( (row-1)>=0? dp[row-1][col]:0 ) + ( (col-1)>=0? dp[row][col-1]:0 );
            }
        }
        return dp[m-1][n-1];
    }
};

// Space Optimized DP
// Time Complexity O(m*n) Space Complexity O(min(m,n))
class Solution {
public:
    int uniquePaths(int m, int n) {
        int mini=min(m,n);
        if(mini==m) return compute(n,m); // Send minimum as columns hence swap
        else return compute(m,n); 
    }

    int compute(int rows,int cols){
        vector<int> dp(cols,0);
        dp[0]=1;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(row==0 && col==0) continue;
                if(col-1>=0) dp[col]+=dp[col-1];
            }
        }
        return dp[cols-1];
    }
};
#include<bits/stdc++.h>
using namespace std;

// Recursive Solution
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size();
        int cols=obstacleGrid[0].size();
        return rec(rows-1,cols-1,obstacleGrid);
    }
        int rec(int row,int col,vector<vector<int>>& grid){
        if(row<0 || col<0) return 0;
        if(grid[row][col]==1) return 0;
        if(row==0 && col==0) return 1;
        return rec(row-1,col,grid)+rec(row,col-1,grid);
    }
};

// Memoized Version
// Time Complexity O(m*n) // Space Complexity O(m*n)+O(m+n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size();
        int cols=obstacleGrid[0].size();
        vector<vector<int>> dp(rows,vector<int> (cols,-1));
        return rec(rows-1,cols-1,obstacleGrid,dp);
    }
        int rec(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(row<0 || col<0) return 0;
        if(grid[row][col]==1) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        if(row==0 && col==0) return 1;
        return dp[row][col]=rec(row-1,col,grid,dp)+rec(row,col-1,grid,dp);
    }
};

// Tabulation Version
// Time Complexity O(m*n) // Space Complexity O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(m==0 || n==0) return 0;
        if(obstacleGrid[0][0]==1) return 0; // This is important i ate 3 4 wrong submission because of this
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if((row==0 && col==0) || obstacleGrid[row][col]==1) continue;
                dp[row][col]= ( (row-1)>=0? dp[row-1][col]:0 ) + ( (col-1)>=0? dp[row][col-1]:0 );
            }
        }
        return dp[m-1][n-1];
    }
};

// Space Optimized DP
// Time Complexity O(m*n) Space Complexity O(n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        return compute(m,n,obstacleGrid); 
    }

    int compute(int rows,int cols,vector<vector<int>>& obstacleGrid){
        vector<int> dp(cols,0);
        if(rows==0 || cols==0 || obstacleGrid[0][0]==1) return 0;
        dp[0]=1;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(row==0 && col==0)  continue;
                if(obstacleGrid[row][col]==1) { // Improtant to reset the cell to 0 because there won't be any contributions from there
                    dp[col]=0;
                    continue;
                }
                if(col-1>=0) dp[col]+=dp[col-1];
            }
        }
        return dp[cols-1];
    }
};

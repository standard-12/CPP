#include<bits/stdc++.h>
using namespace std;

// Recursive Solution 

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        return   rec(rows-1,cols-1,grid,0);
    }
    int rec(int row,int col,vector<vector<int>>& grid,int cost){
        if(row==0 && col==0) return cost+grid[row][col];
        if(row<0 || col<0) return INT_MAX;
        return min( rec(row-1,col,grid,cost+grid[row][col]) , rec(row,col-1,grid,cost+grid[row][col]) );
    } 
};

// This is a classic mistake in DP it seems
// I directly tried to memoize the above version but that fails for e.g for [[1,2,5][3,2,1]]
// Because it will store wrong answer at first and then doesn't allow to update because now dp[row][col]!=-1
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {                                                                         // W
        int rows=grid.size();                                                                                           // R
        int cols=grid[0].size();                                                                                        // O
        vector<vector<int>> dp(rows,vector<int>(cols,-1));                                                              // N
        return  rec(rows-1,cols-1,grid,0,dp);                                                                           // G
    }
    int rec(int row,int col,vector<vector<int>>& grid,int cost,vector<vector<int>>& dp){
        if(row==0 && col==0) return cost+grid[row][col];
        if(row<0 || col<0) return INT_MAX;
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=min( rec(row-1,col,grid,cost+grid[row][col],dp) , rec(row,col-1,grid,cost+grid[row][col],dp) );
    } 
};

// This is the correct memoization (i only came up with this but yeaa the above was a classic mistake)
// Apparently in the above cost is a parameter hence the DP state also depends on the cost 
// Here we eliminate cost ( i.e cost to reach there completely) we just define the recursive function to give the minimum distance from that 
// point to the point [0,0] and then we add the cost of that cell ( before we used to add it before and then send forward )
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        return  rec(rows-1,cols-1,grid,dp);
    }
    int rec(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(row==0 && col==0) return grid[row][col];
        if(row<0 || col<0) return INT_MAX;
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=grid[row][col]+min( rec(row-1,col,grid,dp) , rec(row,col-1,grid,dp) ); // Go up and left and take minimum of that 
    } 
};

// Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int val=grid[i][j];
                int fromUp=i-1>=0? dp[i-1][j]:1e7;
                int fromLeft=j-1>=0? dp[i][j-1]:1e7; // Just to prevent overflow in next line otherwise INT_MAX works
                dp[i][j]=min(val+fromUp,val+fromLeft);
            }
        }
        return dp[m-1][n-1];
    }
};

// Space Optimized DP
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dp(n,0);
        dp[0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int val=grid[i][j];
                int fromUp=i-1>=0? dp[j]:1e7;
                int fromLeft=j-1>=0? dp[j-1]:1e7;
                dp[j]=min(val+fromUp,val+fromLeft);
            }
        }
        return dp[n-1];
    }
};
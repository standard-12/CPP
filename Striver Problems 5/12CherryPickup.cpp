#include<bits/stdc++.h>
using namespace std;

// I tried for hours to solve this and then came up with this solution this passed half of the test cases but this 
// solution is WRONG
// What i am doing here is building DP array then using that DP array i choose a best path using greedy method and set grids to zero in that 
// path ( i.e i am pickign up cherries from the best path)
// Then reset dp array and perform the same again to get the second best path

// But i completely missed that 
// [
//   [0, 0, 0], 
//   [1, 2, 1],  
//   [1, 2, 0]
// ]
// Here my best path will be something like (0,0)->(1,0)->(1,1)->(2,1)->(2,2) & grid will become like this
// [
//   [0, 0, 0], 
//   [0, 0, 1],  
//   [1, 0, 0]
// ]
// But there are better paths than this like (0,0)->(1,0)->(2,0)->(2,1)->(2,2) & (2,2)->(1,2)->(1,1)->(1,0)/(0,1)->(0,0)
// This means the second path is dependent of first path and they both are not independent
// Hence to get best we should perform it together i.e 3D DP or 2-agent DP 
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==-1) return 0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // Build DP
        buildDP(grid,dp);
        // GetCount in first time
        int count=dp[0][0]==-1? 0:dp[0][0];
        // Greedily Make it Zero
        zeroMarker(grid,dp,0,0);
        // Reset
        dp.clear();
        dp.assign(n,vector<int> (n,-1));
        // Build DP
        buildDP(grid,dp);
        count+=(dp[0][0]==-1? 0:dp[0][0]);
        return count;
    }

    void buildDP(vector<vector<int>>& grid,vector<vector<int>>& dp){
        int n=grid.size();
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==n-1 && j==n-1) {
                    dp[i][j]=grid[i][j];
                    continue;
                }
                if(grid[i][j]==-1) continue;
                else {
                    int val=grid[i][j];
                    int fromRight=( j+1<n? dp[i][j+1]:0);
                    int fromDown=( i+1<n? dp[i+1][j]:0);
                    if(fromRight==-1 && fromDown==-1) continue;
                    int choose=max(val+fromRight,val+fromDown);
                    dp[i][j]=choose;
                }
            }
        }
    }

    void zeroMarker(vector<vector<int>>& grid,vector<vector<int>>& dp,int row,int col){
        int n=grid.size();
        if(row>=n || col>=n) return;
        grid[row][col]=0;
        int toRight=INT_MIN,toDown=INT_MIN;
        if(row+1<n) toDown=dp[row+1][col];
        if(col+1<n) toRight=dp[row][col+1];
        if(toDown>toRight) zeroMarker(grid,dp,row+1,col);
        else zeroMarker(grid,dp,row,col+1);
    }
};

// Here is the Solution with recursion+memoization ( This is the standard way to solve not the tabular version but this can be optimized to 3D)
// Time Complexity O(4*n^4) Space Complexity O(n^4)+O(2n)

class Solution {
    int dp[50][50][50][50];
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        int ans=helper(0,0,0,0,n,grid);
        return ans<0? 0:ans;
    }

    int helper(int r1,int c1,int r2,int c2,int N,vector<vector<int>>& grid){
        if(r1>=N || c1>=N || r2>=N || c2>=N || grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
        if(r1==N-1 && c1==N-1) return grid[r1][c1]; // This occurs only when both are in the GOAL state 
        // Because since in this que we can move only down and right there is a relation 
        // r1+c1==r2+c2;

        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2]; // Early returns
        int cherries=0;
        if(r1==r2 && c1==c2) cherries+=grid[r1][c1];
        else cherries+=grid[r1][c1]+grid[r2][c2];
        int f1=helper(r1,c1+1,r2,c2+1,N,grid); // Both move right
        int f2=helper(r1,c1+1,r2+1,c2,N,grid); // One Moves Right the other Moves Down
        int f3=helper(r1+1,c1,r2+1,c2,N,grid); // Both move Down
        int f4=helper(r1+1,c1,r2,c2+1,N,grid); // One moves Down the other moves Right
        cherries+=max(max(f1,f2),max(f3,f4));
        return dp[r1][c1][r2][c2]=cherries;
    }
};

// 3D-DP Memoization 
// Time Complexity O(4*n^4) Space Complexity O(n^3)+O(2n)

class Solution {
    int dp[50][50][50];
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        int ans=helper(0,0,0,n,grid);
        return ans<0? 0:ans;
    }

    int helper(int r1,int c1,int r2,int N,vector<vector<int>>& grid){
        int c2=r1+c1-r2; // Get c2 from other 3
        if(r1>=N || c1>=N || r2>=N || c2>=N || grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
        if(r1==N-1 && c1==N-1) return grid[r1][c1]; // This occurs only when both are in the GOAL state 
        if(dp[r1][c1][r2]!=-1) return dp[r1][c1][r2]; // Early returns
        
        int cherries=0;
        if(r1==r2) cherries+=grid[r1][c1]; // If r1==r2 then c1==c2 since(r1+c1=r2+c2)
        else cherries+=grid[r1][c1]+grid[r2][c2];
        int f1=helper(r1,c1+1,r2,N,grid); // Both move right
        int f2=helper(r1,c1+1,r2+1,N,grid); // One Moves Right the other Moves Down
        int f3=helper(r1+1,c1,r2+1,N,grid); // Both move Down
        int f4=helper(r1+1,c1,r2,N,grid); // One moves Down the other moves Right
        cherries+=max(max(f1,f2),max(f3,f4));
        return dp[r1][c1][r2]=cherries;
    }
};

// The tabulation solution is very difficult and mechanical it's not intuitive at all and hence it is not needed 
// Just for reference 
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxK = 2 * (n - 1);

        vector<vector<vector<int>>> dp(
            maxK + 1,
            vector<vector<int>>(n, vector<int>(n, -1e9))
        );

        dp[0][0][0] = grid[0][0];

        for (int k = 1; k <= maxK; k++) {
            for (int r1 = max(0, k - (n - 1)); r1 <= min(n - 1, k); r1++) {
                for (int r2 = max(0, k - (n - 1)); r2 <= min(n - 1, k); r2++) {

                    int c1 = k - r1;
                    int c2 = k - r2;

                    if (c1 >= n || c2 >= n) continue;
                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;

                    int best = -1e9;

                    // 4 transitions
                    for (int dr1 : {0, 1}) {
                        for (int dr2 : {0, 1}) {
                            int prev_r1 = r1 - dr1;
                            int prev_r2 = r2 - dr2;

                            if (prev_r1 < 0 || prev_r2 < 0) continue;

                            best = max(best, dp[k-1][prev_r1][prev_r2]);
                        }
                    }

                    if (best < 0) continue;

                    int cherries = grid[r1][c1];
                    if (r1 != r2) cherries += grid[r2][c2];

                    dp[k][r1][r2] = best + cherries;
                }
            }
        }

        return max(0, dp[maxK][n-1][n-1]);
    }
};
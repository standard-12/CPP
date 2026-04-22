#include<bits/stdc++.h>
using namespace std;

// This is Memoizatoin Solution 
// I first wrote 4D then wrote 3D since rows will be same 
// Time Complexity O(9*n*m^2) Space Complexity O(n^3)+O(n)
class Solution {
    int dp[70][70][70];
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        memset(dp,-1,sizeof(dp));        
        return rec(grid,0,0,cols-1);
        
    }

    int rec(vector<vector<int>>& grid,int r1,int c1,int c2){
        int rows=grid.size(),cols=grid[0].size(),r2=r1;
        if(r1>=rows || c1>=cols || c1<0 || c2>=cols || c2<0) return INT_MIN;
        if(r1==rows-1 && c1!=c2) return grid[r1][c1]+grid[r2][c2];
        else if(r1==rows-1 && c1==c2 ) return grid[r1][c1];
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        int cherries=0;
        if(c1==c2) cherries+=grid[r1][c1];
        else cherries+=grid[r1][c1]+grid[r2][c2];

        int maxi=INT_MIN;
        for(int i=-1;i<=1;i++){ //
            int opt1=rec(grid,r1+1,c1-1,c2+i); // When bot1 goes left bot2 has 3 options
            int opt2=rec(grid,r1+1,c1,c2+i); // Bot1 goes down and bot2 has 3 options
            int opt3=rec(grid,r1+1,c1+1,c2+i); // Bot1 goes right and bot2 has three options
            maxi=max(max(maxi,opt1),max(opt2,opt3));
        }
        cherries+=maxi;
        return dp[r1][c1][c2]=cherries;
    }
};
// Striver told tabulation not necessary but i am happy i could come up with it on my own
// Yeee i wrote the tabulation DP on my own  Time Complexity O(9*m*(n^2)) Space Complexity O(m*(n^2))
    // But initially i made a mistake by initializing the state as below this is wrong because the dp is the state dp[r1][c1][c2] 
    // where r1 is the row c1 is the column of first robot and c2 is the column of second robot 
        // dp[0][0][0]=grid[0][0]; 
        // dp[0][0][n-1]=grid[0][n-1];
    // Correct initilaization is 
    // dp[0][0][n-1]=grid[0][0]+grid[0][n-1];  // But handle cases like single column
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int dp[m][n][n]; // r1 c1 c2 (row firstBot secondBot)
        memset(dp,-1,sizeof(dp));
        dp[0][0][n-1]=grid[0][0]+grid[0][n-1]; 
        if(m==1 && n!=1) return dp[0][0][n-1];
        if(m==1 && n==1) return grid[0][0]; // Only once
        if(n==1) dp[0][0][n-1]/=2; // Divide by 2 if only one column because we added 2 times above
        int ans=INT_MIN;

        for(int row=1;row<m;row++){
            for(int c1=0;c1<n;c1++){
                for(int c2=0;c2<n;c2++){
                    int maxi=INT_MIN;

                    int cherries=0;
                    if(c1==c2) cherries+=grid[row][c1];
                    else cherries+=grid[row][c1]+grid[row][c2]; 

                    for(int d1=-1;d1<=1;d1++){
                        for(int d2=-1;d2<=1;d2++){
                            int newc1=c1+d1;
                            int newc2=c2+d2;
                            int newrow=row-1; // prev row
                            if(newc1<0 || newc1>=n || newc2<0 || newc2>=n || dp[newrow][newc1][newc2]==-1) continue;
                            maxi=max(maxi,dp[newrow][newc1][newc2]);
                        }
                    }

                    dp[row][c1][c2]=cherries+maxi;
                    if(row==m-1) ans=max(ans,dp[row][c1][c2]); // max of the all combinations for that row
                }
            }
        }
        return ans;
    }

};

// Space Optimized DP
// Time Complexity (9*m*(n^2)) Space Complexity O(2*(n^2))
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n,vector<int>(n,-1))); // r1 c1 c2 (row firstBot secondBot)
        dp[0][0][n-1]= (n!=1? grid[0][0]+grid[0][n-1]:grid[0][0]); 
        if(m==1 && n!=1) return dp[0][0][n-1];
        if(m==1 && n==1) return grid[0][0]; // Only once
        int ans=INT_MIN;

        for(int row=1;row<m;row++){
            for(int c1=0;c1<n;c1++){
                for(int c2=0;c2<n;c2++){
                    int maxi=INT_MIN;
                    int cherries=0;
                    if(c1==c2) cherries+=grid[row][c1];
                    else cherries+=grid[row][c1]+grid[row][c2]; 
                    for(int d1=-1;d1<=1;d1++){
                        for(int d2=-1;d2<=1;d2++){
                            int newc1=c1+d1;
                            int newc2=c2+d2;
                            if(newc1<0 || newc1>=n || newc2<0 || newc2>=n || dp[0][newc1][newc2]==-1) continue;
                            maxi=max(maxi,dp[0][newc1][newc2]);
                        }
                    }
                    if(maxi!=INT_MIN) dp[1][c1][c2]=cherries+maxi;
                    if(row==m-1) ans=max(ans,dp[1][c1][c2]); // max of the all combinations for that row
                }
            }
            dp[0]=dp[1];
            dp[1].assign(n,vector<int>(n,-1));
        }
        return ans;
    }

};
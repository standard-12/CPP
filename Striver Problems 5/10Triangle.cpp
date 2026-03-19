#include<bits/stdc++.h>
using namespace std;

// This is the memoized solution but this was giving TLE in LC although constraint was 200 (may be they have set spcial limit for this que)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return rec(0, 0, triangle, dp);
    }

    int rec(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        int n = triangle.size();

        if (row == n - 1) return triangle[row][col];

        if (dp[row][col] != -1) return dp[row][col];

        int down = rec(row + 1, col, triangle, dp);
        int diag = rec(row + 1, col + 1, triangle, dp);

        return dp[row][col] = triangle[row][col] + min(down, diag);
    }
};

// This was my tabulation method which was starting from row 0 and going till row n-1
// Time Complexity O(n^2) Space Complexity O(n^2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,1e9));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j<triangle[i].size()) dp[i][j]=triangle[i][j];
                else break;

                int up=1e9,upleft=1e9,ans=1e9;
                up=dp[i-1][j];
                if(j>0) upleft=dp[i-1][j-1];
                ans=triangle[i][j] + min(up,upleft );
                dp[i][j]=ans;
            }
        }
        int finalAns=1e9;
        for(int i=0;i<triangle[n-1].size();i++){
            finalAns=min(finalAns,dp[n-1][i]);
        }
        return finalAns;
    }
};

// but this tabulation is more better than the above one this starts from row n-1 and goes to row 0 
// And uses only O(n) space ( we can reduce space to O(n) in above also but this is more easy to understand)
// Time Complexity O(n^2) Space Complexity O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp(n,0);
        dp=triangle[n-1];
        for(int row=n-2;row>=0;row--){
            for(int col=0;col<=row;col++){
                int val=triangle[row][col];
                dp[col]=min(val+dp[col],val+dp[col+1]);
            }
        }
        return dp[0];
    }
};
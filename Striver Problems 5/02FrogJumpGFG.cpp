#include<bits/stdc++.h>
using namespace std;

// This is the recursive solution the ultimate brute force with all the paths 
// We can't memoize this with this logic because it's exploring all the paths
// To memoize we need to modify the logic to find the shortest distance from that index to the last index
class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int mini=INT_MAX;
        int n=height.size();
        rec(0,n,height,mini,0);
        return mini;
    }
    
    void rec(int ind,int n,vector<int>& height,int& mini,int cost){
        if(ind==n-1) {
            mini=min(mini,cost);
        }
        if(ind>=n) return;
        if(ind+1<n) {
            int diff1=abs(height[ind]-height[ind+1]);
            rec(ind+1,n,height,mini,cost+diff1);
        }
        if(ind+2<n) {
            int diff2=abs(height[ind]-height[ind+2]);
            rec(ind+2,n,height,mini,cost+diff2);
        }
    }
    
};

// Memoized Version
// here rec computes the minimum cost from index i to the last/target index (the last function
// was just exploring all the possible paths and taking minimum of it )
// Time Complexity O(2n) // Space Complexity O(2n) (n for dp n for recursion stack) 
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int> dp(n,-1);
        return rec(height,dp,0);
    }
    
    int rec(vector<int>& height,vector<int>& dp,int ind){
        if(ind==height.size()-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int cost1=abs(height[ind]-height[ind+1])+rec(height,dp,ind+1); //Cost if we jump 1 step from here
        int cost2=INT_MAX;
        if(ind+2<height.size()) cost2=abs(height[ind]-height[ind+2])+rec(height,dp,ind+2);
        dp[ind]=min(cost1,cost2);
        return dp[ind];
    }
};

// The Tabular DP
// yee i wrote this on my own woww dp is nice
class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        if(n==2) return abs(height[1]-height[0]);
        vector<int> dp(n,0);
        dp[0]=0;
        dp[1]=abs(height[1]-height[0]);
        for(int i=2;i<n;i++){
            int cost1=abs(height[i]-height[i-2]);
            int cost2=abs(height[i]-height[i-1]);
            dp[i]=min(cost1+dp[i-2],cost2+dp[i-1]);
        }
        return dp[n-1];
    }
};

// Space Optimize DP 

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        if(n==1) return 0;
        if(n==2) return abs(height[1]-height[0]);
        // vector<int> dp(n,0);
        int a=0;
        int b=abs(height[1]-height[0]);
        for(int i=2;i<n;i++){
            int cost1=abs(height[i]-height[i-2]);
            int cost2=abs(height[i]-height[i-1]);
            int c=min(cost1+a,cost2+b);
            a=b;
            b=c;
        }
        return b;
    }
};

// This is a diff video in striver but it's nearly same
// Frog can jump K distance from the current index

// Memoized 
class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n=heights.size();
        vector<int> dp(n,-1);
        return rec(heights,dp,0,k);
    }
    int rec(vector<int>& height,vector<int>& dp,int ind,int k){
        int n=height.size();
        if(ind==n-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int mini=INT_MAX;
        for(int i=ind+1;i<n && i<=ind+k;i++){
            int fixCost=abs(height[ind]-height[i]);
            mini=min(mini,fixCost+rec(height,dp,i,k));
        }
        dp[ind]=mini;
        return dp[ind];
    }
};

// Tabulation

class Solution {
public:
    int frogJump(vector<int>& height, int k) {
        int n = height.size();
        vector<int> dp(n, 0);

        dp[n-1] = 0;

        for(int i = n-2; i >= 0; i--) {
            int mini = INT_MAX;

            for(int j = i+1; j < n && j <= i+k; j++) {
                int cost = abs(height[i] - height[j]) + dp[j];
                mini = min(mini, cost);
            }

            dp[i] = mini;
        }

        return dp[0];
    }
};

// Space Can'e be optimized to O(1) but can be optimized to O(k)

class Solution {
public:
    int frogJump(vector<int>& height, int k) {
        int n = height.size();

        // stores dp[i+1] ... dp[i+k]
        vector<int> window(k, INT_MAX);

        // dp[n-1] = 0 → first element in window
        window[0] = 0;

        for(int i = n-2; i >= 0; i--) {
            int mini = INT_MAX;

            for(int j = 1; j <= k && i + j < n; j++) {
                int cost = abs(height[i] - height[i+j]) + window[j-1];
                mini = min(mini, cost);
            }

            // shift window right
            for(int t = k-1; t > 0; t--) {
                window[t] = window[t-1];
            }

            window[0] = mini;
        }

        return window[0];
    }
};

// But above time complexity increased to O(n*2k) & Space O(k)
// We can us a deque<int> instead so the time complexity will be O(n*k)

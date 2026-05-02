#include<bits/stdc++.h>
using namespace std;

// Memoized Solution  
// Time Complexity O(n*sum) Space Complexity O(n*sum)+O(n)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum,-1));
        int ans= rec(arr,0,0,sum,dp);
        return ans==1? true:false;
    }
    
    int rec(vector<int>& arr,int i,int sum,int target,vector<vector<int>>& dp){
        if(sum==target){
            return 1;
        }
        if(i>=arr.size() || sum>target) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        int val=arr[i];
        dp[i][sum]=max(rec(arr,i+1,sum+val,target,dp),rec(arr,i+1,sum,target,dp));
        return dp[i][sum];
    }
};

// Tabulation Solution
// Time Complexity O(n*sum) Space Complexity O(n*sum)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false)); // Note Sum+1 because sum is a state
        
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(arr[0]<=sum) dp[0][arr[0]]=true;
        
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=sum;target++){
                bool take=false;
                if(target-arr[ind]>=0) take=dp[ind-1][target-arr[ind]];
                
                bool nontake=dp[ind-1][target];
                
                dp[ind][target]=take || nontake;
            }
        }
        return dp[n-1][sum];
        
    }
};

// Space Optimization  Space Complexity O(2*sum) 
// This can still be optimized to 1D array but we have to traverse reverse from target to zero
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<bool>> dp(2,vector<bool>(sum+1,false)); // Note Sum+1 because sum is a state
        
        for(int i=0;i<2;i++) dp[i][0]=true;
        if(arr[0]<=sum) dp[0][arr[0]]=true;
        
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=sum;target++){
                bool take=false;
                if(target-arr[ind]>=0) take=dp[0][target-arr[ind]];
                
                bool nontake=dp[0][target];
                
                dp[1][target]=take || nontake;
            }
            dp[0]=dp[1];
            dp[1].assign(sum+1,false);
        }
        return dp[0][sum];
    }
};

// This was my first code i don't knwo i knew we shouldn't update future states but i still did here
// Actually this will get accpeted but there is a problem the dp states are getting reinitalized in some cases 
// Because of dp[ind+1][sum+val] and in next dp[ind][sum] both are same states actually but this will work BUT WRONG

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum + 1, -1)); // FIXED size
        int ans = rec(arr, 0, 0, sum, dp);
        return ans == 1;
    }
    
    int rec(vector<int>& arr, int i, int sum, int target, vector<vector<int>>& dp) {
        if (sum == target) {
            return 1;
        }
        if (i >= arr.size() || sum > target) return 0;
        
        if (dp[i][sum] != -1) return dp[i][sum];
        
        int val = arr[i];
        
        if (i + 1 <= arr.size() && sum + val <= target)
            dp[i + 1][sum + val] = rec(arr, i + 1, sum + val, target, dp);
        
        dp[i][sum] = rec(arr, i + 1, sum, target, dp);
        
        int ans = -1;
        
        if (i + 1 <= arr.size() && sum + val <= target)
            ans = max(dp[i][sum], dp[i + 1][sum + val]);
        else
            ans = dp[i][sum];
        
        return ans;
    }
};


#include<bits/stdc++.h>
using namespace std;

// I solved it on my own but it is better to solve from last index to first so we can directly replace the states when doing 
// tabulation otherwise if we do like this either we should do tabulation from last or we should figure out the previous state etc
// and do the tabulation also on our own
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        unordered_map<int,unordered_map<int,int>> mp; // also this can be replaced with a vector if we use sum variable in recursion
        return rec(arr,0,target,mp);
    }
    
    int rec(vector<int>& arr,int i,int target,unordered_map<int,unordered_map<int,int>>& mp){
        if(i==arr.size()){
            if(target==0) return 1;
            return 0;
        }
        if(mp.count(i) && mp[i].count(target)) return mp[i][target];
        int take=-1,nontake=-1;
        take=rec(arr,i+1,target-arr[i],mp); // We can optimize using a if condition here if(target>=arr[i])
        nontake=rec(arr,i+1,target,mp);
        return mp[i][target]=take+nontake;
    }
};

// Tabulation Solution Actuallly i shound't have used unordered_map in the above problem i thought there are negatives but there aren't

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;

        if(arr[0] != 0 && arr[0] <= target)
            dp[0][arr[0]] = 1;

        for(int i=1;i<n;i++){
            for(int sum=0;sum<=target;sum++){
                int take=0,nontake=0;
                if(sum-arr[i]>=0) take=dp[i-1][sum-arr[i]];
                nontake=dp[i-1][sum];
                dp[i][sum]=take+nontake;
            }
        }
        return dp[n-1][target];
    }
};
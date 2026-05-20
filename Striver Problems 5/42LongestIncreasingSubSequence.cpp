#include<bits/stdc++.h>
using namespace std;

// The memoization Solution 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // unordered_map<int,unordered_map<int,int>> mp;
        vector<vector<int>> dp(n,vector<int>(n+1,INT_MIN));
        return rec(nums,n-1,-1,dp);
    }

    int rec(vector<int>& nums,int i,int prevInd,vector<vector<int>>& dp){
        if(i==0){
            return prevInd==-1 || nums[0]<nums[prevInd]? 1:0;
        }
        if( dp[i][prevInd+1]!=INT_MIN) return dp[i][prevInd+1];
        int opt1=0,opt2=0;
        if(prevInd==-1 || nums[i]<nums[prevInd]){
            opt1=1+rec(nums,i-1,i,dp);
        }
        opt2=rec(nums,i-1,prevInd,dp);
        return dp[i][prevInd+1]=max(opt1,opt2);
    }
};

// The O(nlogn) method and the most optimal one 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> LIS;
        for(int x:nums){
            int ind=lb(LIS,x);

            if(ind==-1){
                LIS.push_back(x);
            }
            else {
                LIS[ind]=x;
            }
        }
        return LIS.size();
    }

    int lb(vector<int>& nums,int target){
        int n=nums.size();
        int beg=0,end=n-1,ans=-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(nums[mid]>=target){
                ans=mid;
                end=mid-1;
            }
            else {
                beg=mid+1;
            }
        }
        return ans;
    }
};

// Tabulation for my recursive solution 
// Note the difference in replacements because here we check dp[i][prevInd+1]!=INT_MIN in the recursion stats
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // unordered_map<int,unordered_map<int,int>> mp;
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            if(nums[0]<nums[i]) dp[0][i+1]=1;
            else dp[0][i+1]=0;
        }

        for(int i=1;i<n;i++){
            for(int prevInd=n-1;prevInd>=-1;prevInd--){
                int opt1=0,opt2=0;
                if(prevInd==-1 || nums[i]<nums[prevInd]){
                    opt1=1+dp[i-1][i+1];
                }
                opt2=dp[i-1][prevInd+1];
                dp[i][prevInd+1]=max(opt1,opt2);
            }
        }
        return dp[n-1][0];
    }
};

// The Space Optimized O(n) space solution it's not like above this is bit different
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }   
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};

// This is O(n) space Solution of Striver with hash array

class Solution {
  public:
    vector<int> getLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),hash(n,0);
        int maxi=1,maxInd=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(1+dp[j]>dp[i]){
                        hash[i]=j;
                        dp[i]=1+dp[j];
                    }
                }   
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                maxInd=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[maxInd]);
        while(hash[maxInd]!=maxInd){
            maxInd=hash[maxInd];
            ans.push_back(nums[maxInd]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
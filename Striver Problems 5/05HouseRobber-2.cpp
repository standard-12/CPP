#include<bits/stdc++.h>
using namespace std;

// I couldn't solve this on my own 
// it's just previous problem divided into two parts 
// 0 to n-2 & 1 to n-1
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n-1;i++){
            int take = nums[i] + (i-2>=0? dp[i-2]:0);
            int nonTake = dp[i-1];
            dp[i]=max(take,nonTake);
        }
        int maxi1=dp[n-2];
        // Clear the array and do for 1 to n-1
        dp.clear();
        dp[1]=nums[1]; // Start with nums1
        for(int i=2;i<n;i++){
            int take = nums[i] + (i-2>=1? dp[i-2]:0);
            int nonTake = dp[i-1];
            dp[i]=max(take,nonTake);
        }
        int maxi2=dp[n-1];
        return max(maxi1,maxi2);
    }
};
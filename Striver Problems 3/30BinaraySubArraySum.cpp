#include<bits/stdc++.h>
using namespace std;

// This was my solution and this is the optimal solution
// Time Complexity O(2*2n) Space Complexity O(1)
// This approach is only for non negative sums (see explantion below)

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarrayWithSumLessThanOrEqualToK(nums,goal)-subarrayWithSumLessThanOrEqualToK(nums,goal-1);
    }

    int subarrayWithSumLessThanOrEqualToK(vector<int>& nums,int k){
        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int cnt=0;
        while(j<n){
            sum+=nums[j];
            while(i<n && i<j && sum>k){
                sum-=nums[i];
                i++;
            }
            if(sum<=k) cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
};

/* The two-pointer / sliding window method assumes: when you move the right pointer j forward,
 the window sum sum = sum(nums[i..j]) does not decrease (it either stays same or increases).
 That lets you only ever move the left pointer i forward to restore sum <= k. */

/* If elements can be negative, adding nums[j+1] can decrease the window sum. That means a subarray that was invalid earlier (when you moved 
i forward) can become valid after adding a negative, but you can’t move i backward — so you miss those valid subarrays.*/


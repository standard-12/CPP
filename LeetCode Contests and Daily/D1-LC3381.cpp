#include<bits/stdc++.h>
using namespace std;
// This i got from daily question , I had nearly solved it but had to see the solution at the end
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long maxSum=LLONG_MIN;
        vector<long long> kMap(k,LLONG_MAX/2); // To prevent overflow
        kMap[k-1]=0;
        long long currSum=0;
        for(int i=0;i<nums.size();i++){
            currSum+=nums[i];
            maxSum=max(maxSum,currSum-kMap[i%k]);
            kMap[i%k]=min(kMap[i%k],currSum);
        }
        return maxSum;
    }
};
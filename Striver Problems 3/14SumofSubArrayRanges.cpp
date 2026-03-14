#include<bits/stdc++.h>
using namespace std;

// Just edit the code for SumofSubArrayMinimums to Maximums and give the difference
// I thought so much to find a way to get both min and max of subarray together but this solution didn't strike me
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long  minSum=sumSubarrayMins(nums);
        long long  maxSum=sumSubarrayMaxs(nums);
        return maxSum-minSum;
    }
    long long sumSubarrayMins(vector<int>& nums){
        return 0;
    }
    long long sumSubarrayMaxs(vector<int>& nums){
        return 0;
    }
};


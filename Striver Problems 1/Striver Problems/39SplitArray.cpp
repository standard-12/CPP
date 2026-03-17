#include<bits/stdc++.h>
using namespace std;
// The code is same for Allocation of Pages and Split Array Problem

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int beg=*(max_element(nums.begin(),nums.end()));
        int end=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            bool b=isPossible(nums,mid,k);

            if(b) {
                ans=mid;
                end=mid-1;
            }
            else {
                beg=mid+1;
            }
        }
        return ans;
    }
    bool isPossible(vector<int>& nums,int mid,int k){
        int n=nums.size();
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>mid){
                count++;
                sum=nums[i];
            }
        }
        if(sum<=mid) count++;
        if(count>k) return false;
        return true;
    }
};

// Striver Solution
class Solution2 {
    public :
    int countPartitions(vector<int> &a, int maxSum) {
    int n = a.size(); //size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + a[i] <= maxSum) {
            //insert element to current subarray
            subarraySum += a[i];
        }
        else {
            //insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}

int largestSubarraySumMinimized(vector<int> &a, int k) {
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int partitions = countPartitions(a, mid);
        if (partitions > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}
};

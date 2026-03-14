#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int beg=1;
        int end=n-1;
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;

            else if(nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1]) {
                end=mid-1;
            }
            else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                beg=mid+1;
            }
            else {
                beg=mid+1; //or end=mid-1; both side peak exists
            }
        }
        return -1;
    }    
};


#include<bits/stdc++.h>
using namespace std;


// This was my method but i couldn't code it properly and had used chatGPT but here idea is we find K using binary search then do binary search with k value 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int k = findK(nums);
        return findTarget(nums, target, k);
    }

    int findK(vector<int>& nums) {
        int n = nums.size();
        int beg = 0, end = n - 1;

        if (nums[beg] <= nums[end]) return 0;

        while (beg <= end) {
            int mid = beg + (end - beg) / 2;

            if (mid > 0 && nums[mid] < nums[mid - 1])
                return mid;
            if (mid < n - 1 && nums[mid] > nums[mid + 1])
                return mid + 1;

            if (nums[mid] >= nums[beg])
                beg = mid + 1;
            else
                end = mid - 1;
        }
        return 0;
    }

    int findTarget(vector<int>& nums, int target, int k) {
        int n = nums.size();
        int beg = 0, end = n - 1;

        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            int real_mid = (mid + k) % n;

            if (nums[real_mid] == target)
                return real_mid;
            else if (nums[real_mid] > target)
                end = mid - 1;
            else
                beg = mid + 1;
        }
        return -1;
    }
};


// The striver solution is optimal one it directly finds the sorted half of the array then if target is inside that we search that otherwise we search the other half

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int beg=0;
        int end=n-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;

            if(nums[mid]==target){
                return mid;
            }
            //Left half is sorted else right half is sorted
            else if(nums[mid]>=nums[beg]){ // I figured out that this equal to sign is very important otherwise it will fail in [3,1] i.e 2 numbers
                if(nums[mid]>target && nums[beg]<=target){ // The target exists in sorted array
                    end=mid-1;
                }
                else { 
                    beg=mid+1;
                }
            }
            //else right half
            else {
                if(nums[mid]<target && nums[end]>=target){// The target exists in sorted array
                    beg=mid+1;
                }
                else {
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};

 // This is for when there is duplicates in the array
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int beg=0;
        int end=n-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;

            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]==nums[beg] && nums[mid]==nums[end]){
                end--;
                beg++;
            }
            //Left half is sorted else right half is sorted
            else if(nums[mid]>=nums[beg]){
                if(nums[mid]>target && nums[beg]<=target){
                    end=mid-1;
                }
                else {
                    beg=mid+1;
                }
            }
            //else right half
            else {
                if(nums[mid]<target && nums[end]>=target){
                    beg=mid+1;
                }
                else {
                    end=mid-1;
                }
            }
        }
        return false;
    }
};
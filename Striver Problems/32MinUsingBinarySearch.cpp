#include<bits/stdc++.h>
using namespace std;
// It is rotated SORTED array

// I used this method this is actually code to find the pivot but it will work since minimum will be at the pivot
class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int beg=0;
        int end=n-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;

            if(mid>0 && arr[mid]<arr[mid-1]){
                return arr[mid];
            }
            if(mid<n-1 && arr[mid]>arr[mid+1]){
            return arr[mid+1];
            }
            if(arr[mid]>arr[end]){
                beg=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        return arr[0];
    }
};


// This is another solution
// uses beg<end and end=mid instead of beg<=end and end=mid-1
// this sees if nums[mid]>nums[end] (STRICTLY) that is right half is not sorted for sure and min lies right to the mid (not in mid for sure since mid is already greater than end hence we do beg=mid+1)
// but if right half is sorted then the min might be also the mid or min is in the left half so we do end=mid
// and beg<end because at the end when there is only 2 elements [1,2] or [2,1] in both cases beg will end at minimum
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int beg=0;
        int end=n-1;
        while(beg<end){
            int mid=beg+(end-beg)/2;

            if(nums[mid]>nums[end]){
                beg=mid+1;
            }
            else {
                end=mid;
            }
        }
        return nums[beg];
    }
};

// the striver gave other solution it uses a trick like we take the minimum element from the sorted half and continue normally
// uses beg<=end
// finds the minimum of sorted part and goes to another part because the minimum(the pivot) may be the minimum in sorted part or it(the pivot) is in other half
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int beg=0;
        int end=n-1;
        int ans=INT_MAX;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            
            if(nums[mid]>=nums[beg]){
                ans=min(ans,nums[beg]);
                beg=mid+1;
            }
            else {
                ans=min(ans,nums[mid]);
                end=mid-1;
            }
        }
    return ans;
    }
};
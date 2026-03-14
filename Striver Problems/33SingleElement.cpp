#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n>2){ // this was not required because if n is 1 it'll be returned in previous step then next option is n=3
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        }
        int beg=2;
        int end=n-3;
        while(beg<=end){
            int mid=beg+(end-beg)/2;

            if((mid%2==0)){
                if(nums[mid]==nums[mid+1]){
                    beg=mid+2;
                }
                else if(nums[mid]==nums[mid-1]){
                    end=mid-2;
                }
                else {
                    return nums[mid];
                }
            }
            else {
                if(nums[mid]==nums[mid+1]){
                    end=mid-1;
                }
                else if(nums[mid]==nums[mid-1]){
                    beg=mid+1;
                }
                else {
                    return nums[mid];
                }
            }
        }
        return -1;
    }
};

// Same thing in other way -Striver solution

int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.

    //Edge cases: Since we are doing -2/+2 we should check these cases
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        //we are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            //eliminate the left half:
            low = mid + 1;
        }
        //we are in the right:
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
}
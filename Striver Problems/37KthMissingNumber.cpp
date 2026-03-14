#include<bits/stdc++.h>
using namespace std;

// I found this solution on my own 
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n=nums.size();
        int diff=nums[n-1]-n;
        if(k>diff) return nums[n-1]+k-diff;
        if(k<nums[0]) return k;
        int beg=0;
        int end=n-1;
        int offset=0;
        int missed=0;
        int ans=0;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            missed=(nums[mid]-(mid+1)); // no of missing numbers behind mid
            if(missed<k){ // goes till one number back where the missing number is actually there i,e if 5 is the answer (in this case 3rd missing number) and array is [1,4,6,7] it goes till 4
                ans=mid;
                offset=missed;
                beg=mid+1;
            }
            else {
                end=mid-1;
            }

        }
        return nums[ans]+(k-offset);
    }
};

//THis was the striver solution same logic but less variables 
// this derives a formula for the last line since it doesnt take care of cases k<nums[0] separately
int missingK(vector < int > vec, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1;
}
#include<bits/stdc++.h>
using namespace std;

// I knew the brute force (with sorting ) 
// But question was asking time complexity O(n) and Space Complexity O(1)
// This is the solution 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]<=0) {
                nums[i]=n+1; // Make all positive so we can use negative as an identifier in the future for marking numbers
            }
        }

        for(int i=0;i<n;i++){
            int ind=abs(nums[i]); // Getting actual index (incase if it has turned negative by previous numbers)
            if(ind<=n){
                nums[ind-1]=-1*abs(nums[ind-1]); // Mark the already appeared index as negative don't do -1 * nums[ind-1] (because it might turn postivie if it happens 2 times hence use abs())
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i+1; // The one which didn't turn negative wasn't there in the nums array (with offset of 1)
            }
        }
        return n+1;
    }
};
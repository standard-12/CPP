#include<bits/stdc++.h>
using namespace std;

// Hurray i came up with this on my own and its the optimal solution (but wait!!! it's not optimal)
// Many people accept this solution but there is a better solution
// The TC is O(2n) which can be reduced to O(n) by replacing the while with if in inside the outer while loop

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int ans=0;
        while(i<n && j<n){
            while(j<n && (nums[j]==1 || k>0)){
                if(nums[j]!=1) k--;
                ans=max(ans,j-i+1);
                j++;
            }
            while(i<n && k==0){
                if(nums[i]==0) k++;
                i++;
            }
        }
        return ans;
    }
};

// We can replace the while loop inside by if 
// Like we maintain the window of the CURRENT maxlength of the subarray ( because we are not interseted in solutions less than that length )
// This is possible because they are asking only the length if they asked the subarray with some conditions then this was not possible

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int ans=0;
        int zeroes=0;
        while(j<n){
            if(nums[j]==0) zeroes++;
            if(zeroes>k){
                if(nums[i]==0) zeroes--;
                i++;
            }
            if(zeroes<=k) {  // This is important we update only if it is valid otherwise we keep on moving the window 
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};

// E.g if the array is 1 1 1 1 0 0 0 and k=2
// We reach l=0 and j=5 and when j reach 6 zeroes count is 3
// But in while loop version we move i till 5th pos to make zeroes count 2 
// But in if version we move both i by only one and check if its valid
// So second version its O(n)
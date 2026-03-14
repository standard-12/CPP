#include<bits/stdc++.h>
using namespace std;

// I gave this solution and striver also gave same solution
// Time Complexity O(2*2n) Space Complexity O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);   
    }

    int helper(vector<int>& nums,int k){
        int n=nums.size();
        int i=0;
        int j=0;
        int noOfOdds=0;
        int count=0;
        while(j<n){
            if(nums[j]%2==1) noOfOdds++;
            while(i<n && i<j && noOfOdds>k){
                if(nums[i]%2==1) noOfOdds--;
                i++;
            }
            if(noOfOdds<=k) count+=j-i+1;
            j++;
        }
        return count;
    }
};

// This was there in solutions of leetcode may be this is too much and not required but nice solution
// Time Complexity O(2n) Space Complexity O(1)
// See Andrii Nikolaienko C++: Visual explanation. O(1) space. Two pointers (FOR EXPLANTION)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int j = 0, odd = 0, count = 0, total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                odd++;
                if (odd >= k) {
                    count = 1;
                    while (!(nums[j++] & 1)) count++;
                    total += count;
                }
            } else if (odd >= k) total += count;
        }
        return total;
    }
};
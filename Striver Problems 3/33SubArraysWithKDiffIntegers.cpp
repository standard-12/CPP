#include<bits/stdc++.h>
using namespace std;

// This was marked hard but solved easily

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums,k)-atMostK(nums,k-1);
    }

    int atMostK(vector<int>& nums,int k){
        if(k<0) return 0;
        int n=nums.size();
        int i=0;
        int j=0;
        unordered_map<int,int> freq;
        int count=0;
        while(j<n){
            freq[nums[j]]++;

            while(freq.size()>k){
                freq[nums[i]]--;
                if(freq[nums[i]]==0) freq.erase(nums[i]);
                i++;
            }

            count+=j-i+1;
            j++;
        }
        return count;
    }
};
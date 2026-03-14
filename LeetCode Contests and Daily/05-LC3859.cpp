#include<bits/stdc++.h>
using namespace std;

// Three Pointers method OR Dual Sliding Window Approach 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        long long res=0;
        int leftv=0,leftd=0,vcount=0;
        unordered_map<int,int> countd,countv;
        int n=nums.size();
        for(int i=0;i<n;i++){
            countd[nums[i]]++;
            while(countd.size()>k){
                countd[nums[leftd]]--;
                if(countd[nums[leftd]]==0){
                    countd.erase(nums[leftd]);
                }
                leftd++;
            }
            countv[nums[i]]++;
            if(countv[nums[i]]==m) vcount++;
            while(vcount>=k){
                if(countv[nums[leftv]]==m) vcount--;
                countv[nums[leftv]]--;
                leftv++;
            }
            if(leftv>leftd) res+=(leftv-leftd); 
        }
        return res;
    }
};
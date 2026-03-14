#include<bits/stdc++.h>
using namespace std;

// I couldnt come up with this solution
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
         int beg=1;
         int end=maxi(piles);
         int ans;
         while(beg<=end){
            int mid=beg+(end-beg)/2;
            long long th=totalhrs(piles,mid);
            if(th<=h){
                ans=mid;
                end=mid-1;
            }
            else {
                beg=mid+1;
            }
         }
         return ans;
    }
    int maxi(vector<int>& nums){
        int n=nums.size();
        int m=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>m) m=nums[i];
        }
        return m;
    }
    long long totalhrs(vector<int>& nums,int mid){
        int n=nums.size();
        long long total=0;
        for(int i=0;i<n;i++){
            total+=(nums[i]+mid-1)/mid;
        }
        return total;
    }
};
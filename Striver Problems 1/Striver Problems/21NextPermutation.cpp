#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
    int findK(vector<int>& nums,int size){
        for(int i=size-1;i>0;i--){
            if(nums[i]>nums[i-1]) {
                return i-1;
            }
        }
        return -1;
    }

    int findL(vector<int>& nums,int k,int size){
        for(int i=size-1;i>k;i--){
            if(nums[i]>nums[k]){
                return i;
            }
        }
        return k+1;
    }


    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        int k=findK(nums,size);
        if(k==-1) {sort(nums.begin(),nums.end());}
        else {
        int l=findL(nums,k,size);
        swap(nums[k],nums[l]);
        reverse(nums.begin()+k+1,nums.end());
        }
    }

    int main(){
        vector<int> nums={3,2,1};
        nextPermutation(nums);
        for(auto it:nums) cout<<it<<" ";
        return 0;
    }

    /*
    1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
    2. Find the largest index l greater than k such that a[k] < a[l].
    3. Swap the value of a[k] with that of a[l].
    4. Reverse the sequence from a[k + 1] up to and including the final element a[n].
    */
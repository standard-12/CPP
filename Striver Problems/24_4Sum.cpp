#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int size=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<size-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<size-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int left=j+1;
                int right=size-1;
                long long sum1=nums[i]+nums[j];
                while(left<right){                    
                    long long sum2=nums[left]+nums[right];
                    long long sum=sum2+sum1;
                    if(sum>target){
                        right--;
                    }
                    else if(sum<target){
                        left++;
                    }
                    else {
                        vector<int> temp={nums[i],nums[j],nums[left],nums[right]};
                        ans.push_back(temp);
                        do {
                            left++;
                        }while(left<size-1 && nums[left-1]==nums[left]);
                        do {
                            right--;
                        }while(right>left && nums[right]==nums[right+1]);
                    }
                }
            }
        }
        return ans;
    }
};
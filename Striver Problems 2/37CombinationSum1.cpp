#include<bits/stdc++.h>
using namespace std;

//Time Complexity : O(2^t * k) where t is average of  maximum times a number can be called with all other numbers
// for e.g if arr is [2,1,3] and if target is 8 here then with 2 it can be 2,2,2,2 or 2,2,2,1,1 and with 1 it can be 1,1,1,1,1,1,1,1
// where k is the average length of answer arrays , and time taken to insert it is k
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n=candidates.size();
        vector<int> temp;
        recur(0,0,target,n,candidates,temp,ans);
        return ans;
    }

    void recur(int ind,int sum,int k,int n,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans){
        if(sum==k){
            ans.push_back(temp);
            return;
        }
        if(sum>k || ind==n){
            return;
        }
        sum+=nums[ind];
        temp.push_back(nums[ind]);
        recur(ind,sum,k,n,nums,temp,ans);
        sum-=nums[ind];
        temp.pop_back();
        recur(ind+1,sum,k,n,nums,temp,ans);
    }
};
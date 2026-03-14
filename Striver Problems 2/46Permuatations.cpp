#include<bits/stdc++.h>
using namespace std;

// Approach -1

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> vis(nums.size(),0);
        recur(nums,temp,vis,ans);
        return ans;
    }

    void recur(vector<int>& nums,vector<int>& temp,vector<int>& vis,vector<vector<int>>& ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<vis.size();i++){
            if(vis[i]==1) continue;
            temp.push_back(nums[i]);
            vis[i]=1;
            recur(nums,temp,vis,ans);
            temp.pop_back();
            vis[i]=0;
        }
        return;
    }
};

// Approach - 2 better one with less space 

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recur(nums,0,ans);
        return ans;
    }

    void recur(vector<int>& nums,int begin,vector<vector<int>>& ans){
        if(begin>=nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=begin;i<nums.size();i++){
            swap(nums[i],nums[begin]);
            recur(nums,begin+1,ans);
            swap(nums[i],nums[begin]);
        }
        return;
    }
};
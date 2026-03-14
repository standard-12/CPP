#include<bits/stdc++.h>
using namespace std;

// This was my solution generating all binary digits as string and later using it for generating subsequences
// Time Complexity O(2^N . N) + O(2^N . N) ( one for generating all binary strings another for generating answers);
// Space complexity is N*(2^N) + Recursion depth +  N*2^N for output
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<string> ans;
        vector<vector<int>> finalans;
        helper(nums.size(),ans,"");
        for(int i=0;i<ans.size();i++){
            vector<int> temp;
            for(int j=0;j<ans[0].size();j++){
                if(ans[i][j]=='1') temp.push_back(nums[j]); 
            }
            finalans.push_back(temp);
        }
        return finalans;
    }
    void helper(int num, vector<string>& ans, string temp){
        if(num==temp.size()){
            ans.push_back(temp);
            return;
        }
   
        helper(num , ans, temp+"0");
        helper(num , ans, temp+"1");
    }
};

// This is the power set method
// Time Complexity O(2^N . N)
// Space Complexity is only recursion depth O(n) (if output(N*2^N) is not considered for space complexity)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        int end=(1<<n)-1; // If n is 5 then 00000001 to 00100000 which is 32 => 32-1 =31 
        for(int i=0;i<=end;i++){ // 0 to 31 
            vector<int> temp;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){ // Same thing check if any of the bit is 1 e.g 00100000 checks with 00000001,00000010,00000100,00001000 etc
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// The recursion based solution
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int> temp;
        helper(0,nums,temp,ans,n);
        return ans;
    }
    void helper(int index,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans,int n){
        if(index==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        helper(index+1,nums,temp,ans,n);
        temp.pop_back();
        helper(index+1,nums,temp,ans,n);
    }
};
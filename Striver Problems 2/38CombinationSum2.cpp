#include<bits/stdc++.h>
using namespace std;

// Brute for solution is to create all possible subsequnce and before adding the answer to final ds,check whether it was already added or 
// using unordered_set to have answers and then later convert it to required ds


// This solution uses the normal binary branching pattern (include/exclude) but skips the duplicates but not as efficient as the multibranch 
// recursion which is the optimal solution
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        recur(0,0,target,candidates,temp,ans);
        return ans;
    }

    void recur(int ind,int sum,int k,vector<int>& nums,vector<int>& temp,vector<vector<int>>& st){
        if(sum==k){
            // if(!isDup(temp,st)){
            st.push_back(temp);
            // }
            return;
        }
        if(sum>k || ind==nums.size()) return;
        temp.push_back(nums[ind]);
        recur(ind+1,sum+nums[ind],k,nums,temp,st);
        temp.pop_back();
        int next=ind+1;
        while(next<(int)nums.size() && nums[next]==nums[ind]) next++; // This is to skip duplicates
        recur(next,sum,k,nums,temp,st);
    }

    // bool isDup(vector<int>& nums,vector<vector<int>>& ans){
    //     int n=nums.size();
    //     for(int i=0;i<ans.size();i++){
    //         bool b=true;
    //         int size=ans[i].size();
    //         if(size!=n) continue;
    //         else {     
    //                 for(int j=0;j<size;j++){
    //                     if(nums[j]!=ans[i][j]) b=false;
    //                 }
    //                 if(b) return true;
    //         }
    //     }
    //     return false;
    // }

};

// This is the multibranch solution and the optimal one 

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        recur(0,target,n,candidates,temp,ans);
        return ans;
    }

    void recur(int index,int target,int n,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<n;i++){
            if(i>index && nums[i]==nums[i-1]) continue; // i>ind is important it will not pick duplicates for a particular position for e.g if it is [1,1,1,2] 
            //if we write i>0 instead of i>ind we won't get [1 1] or [1 1 1] but if we use i>ind this will be covered.
            // i.e same element won't be picked for same position like if 1 is picked as a second element then it won't be picked again as second element 
            if(nums[i]>target) break;// because target will go below 0 in this case and Since nums is sorted we can break
            temp.push_back(nums[i]);
            recur(i+1,target-nums[i],n,nums,temp,ans);
            temp.pop_back();
        }
    }
};
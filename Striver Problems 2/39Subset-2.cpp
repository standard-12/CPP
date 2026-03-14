#include<bits/stdc++.h>
using namespace std;

// The following both are valid solutions but the first one generates only the

// Recursion tree for first one
/*                                                   recur(0,temp())
                                    recur(1,temp(1))              recur(2,temp(2))
                            recur(2,temp(1,2))                         recur(3,temp(2,2))
                     recur(3,temp(1,2,2))
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        recur(0,n,nums,temp,ans);
        return ans;
    }

    void recur(int ind,int n,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans){
        ans.push_back(temp);
        for(int i=ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            recur(i+1,n,nums,temp,ans);
            temp.pop_back();
        }
    }
};

// Recursion tree for second one 
/*                                                          recur(0,temp())
                                    recur(1,temp(1))                                           recur(1,temp())
                recur(2,temp(1,2))                 *recur(3,temp(1))                  recur(2,temp(2))                *recur(3,temp())
  *recur(3,temp(1,2,2))    *recur(3,temp(1,2))                              *recur(3,temp(2,2))   *recur(3,temp(2))
  * - leaf node
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        recur(0,n,nums,temp,ans);
        return ans;
    }

    void recur(int ind,int n,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans){
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        recur(ind+1,n,nums,temp,ans);
        temp.pop_back();
        int next=ind+1;
        while(next<n && nums[next]==nums[ind]) next++;
        recur(next,n,nums,temp,ans);
    }
};
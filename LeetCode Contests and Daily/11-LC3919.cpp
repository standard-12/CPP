#include<bits/stdc++.h>
using namespace std;

// A VERY VERY NICE PROBLEM ON PREFIX SUM I COULDN'T SOLVE IT 
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> closest(n);
        closest[0]=1;
        closest[n-1]=n-2;
        for(int i=0;i<n;i++){
            if(i==0 || i==n-1) continue;
            int left=abs(nums[i]-nums[i-1]);
            int right=abs(nums[i]-nums[i+1]);
            closest[i]=left<=right? i-1:i+1;
        }

        vector<int> forward(n,0);
        for(int i=1;i<n;i++){
            int direct=nums[i]-nums[i-1];
            int close =closest[i-1]==i? 1:INT_MAX;
            forward[i]=forward[i-1]+min(direct,close);
        }
        
        vector<int> backward(n,0);
        for(int i=n-2;i>=0;i--){
            int direct=nums[i+1]-nums[i];
            int close = closest[i+1]==i? 1:INT_MAX;
            backward[i]=backward[i+1]+min(direct,close);
        }

        int size=queries.size();
        vector<int> ans(size,0);
        for(int i=0;i<size;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            if(l==r) ans[i]=0;
            else if(l>r) ans[i]=backward[r]-backward[l];
            else ans[i]=forward[r]-forward[l];
        }
        return ans;
    }
};
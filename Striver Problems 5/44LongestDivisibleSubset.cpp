#include<bits/stdc++.h>
using namespace std;

// I thought this is like previous question 
// But here we have to sort because for e.g 9,3,21 but 21 is not divisble by 9 but we get answer as 9,3,21 if we check
// for nums[i]%nums[j]==0 || nums[j]%nums[i]==0 because already we have 9,3 as a subset and now 21%3 comes true so it gets added but actually 21%3 !=0
// Hence it should be sorted while getting the subset
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),hash(n);
        int maxi=1,maxInd=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 ){
                    if(1+dp[j]>dp[i]){
                        hash[i]=j;  
                        dp[i]=1+dp[j];
                    }
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                maxInd=i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[maxInd]);
        while(hash[maxInd]!=maxInd){
            maxInd=hash[maxInd];
            ans.push_back(nums[maxInd]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
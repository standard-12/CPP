#include<bits/stdc++.h>
using namespace std;

// I had the idea but i was doing mistakes in adding it For a dp1[i] i was adding all dp2[j]....dp[n-1]
// But onyl adding dp1[i] and dp2[i] is enoguh since a number will either belong to increasing or decrasing subsequnce 
class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> dp1(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp1[i]=max(dp1[i],1+dp1[j]);
                }   
            }
        }
        
        vector<int> dp2(n,1);
        reverse(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp2[i]=max(dp2[i],1+dp2[j]);
                }   
            }
        }
        reverse(dp2.begin(),dp2.end());
        

        int maxi=0;
        for(int i=0;i<n;i++){
            if(dp1[i]!=1 && dp2[i]!=1)maxi=max(maxi,dp1[i]+dp2[i]-1);
        }
        return maxi;
    }
};

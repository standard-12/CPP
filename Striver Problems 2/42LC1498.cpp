#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> power(n,1);
        int MOD=1e9+7;
        for(int i=1;i<n;i++){
            power[i]=(2*power[i-1])%MOD;
        }
        sort(nums.begin(),nums.end());
        int count=0;
        int i=0;
        int j=n-1;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                count=(count+power[j-i])%MOD;
                i++;
            }
            else {
                j--;
            }
        }
        return count;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int suff=1;
        int maxi=INT_MIN;
        int pref=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(suff==0) suff=1;
            if(pref==0) pref=1;

            suff*=nums[n-1-i];
            pref*=nums[i];
            maxi=max(maxi,max(suff,pref));
        }
        return maxi;
    }
};
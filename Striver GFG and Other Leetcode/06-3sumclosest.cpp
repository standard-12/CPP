#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mini=INT_MAX; // The diff between target and sum
        int ans=0; 
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int diff=abs(target-sum);
                if(diff<mini){
                    mini=diff;
                    ans=sum; // Updating the ans
                }
                if(sum>target){ // This is important i was doing k-- inside the previous diff<mini block which misses some edge cases
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        return ans;
    }
};
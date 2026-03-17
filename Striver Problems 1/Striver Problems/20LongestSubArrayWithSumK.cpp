#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
 // This works only for non-negative intergers 
 // For negative integers we should use prefix sum + index map solution
int longestSubArray(vector<int>& nums,int k){
    int size=nums.size();
    int i=0;
    int j=0;
    int sum=nums[0];
    int maxcnt=0;

    while(j<size){
        while(i<=j && sum>k){
            sum-=nums[i];
            i++;
        }
        if(sum==k) maxcnt=max(maxcnt,j-i+1);

        j++;
        sum+=nums[j];
    }
    return maxcnt;

}

// THis is for arrays containing negatives also
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(mp.count(sum-k)){
                int len=i-mp[sum-k];
                maxi=max(maxi,len);
            }
            if(!mp.count(sum)) mp[sum]=i;
        }
        return maxi;
    }
};

int main(){
    vector<int> nums={2,5,3,2,5,1,0,1,1,0,4};
    int K=10;
    int ans=longestSubArray(nums,K);
    cout<<ans;
    return 0;    
}
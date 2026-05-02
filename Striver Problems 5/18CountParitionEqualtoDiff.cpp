#include<bits/stdc++.h>
using namespace std;

// I did it on myself it's the exact copy of last problem
// 2 ways are there one is need=(sum+diff)/2 and need=(sum-diff)/2 both works both searches for diff subsets but result is same since s1+s2=sum 
class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        if((sum+diff)%2==1) return 0; // Acutally here i should also check if (sum-dff)>0 because if sum is 5 and target is 7 then we will be finding subsets with sum (7+5)/2=6 or (7-5)/2=1
        // Here it worked because we were only doing (sum+diff)/2;
        int need=(sum+diff)/2;
        
        // Based on equation x+y=sum -> Sum of 2 partitions will be equal to total sum
        // Based on x-y=diff; now add both => 2x=sum+diff => x=(sum+diff)/2;
        
        vector<vector<int>> dp(n,vector<int>(need+1,0));
        
        if(arr[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        
        if(arr[0]!=0 && arr[0]<=need) dp[0][arr[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int target=0;target<=need;target++){
                int take=0,nontake=0;
                if(target-arr[i]>=0) take=dp[i-1][target-arr[i]];
                nontake=dp[i-1][target];
                dp[i][target]=take+nontake;
            }
        }
        return dp[n-1][need];
    
    }
};

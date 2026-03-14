#include<bits/stdc++.h>
using namespace std;

// This should have been solved early 
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int ans=-1;
        int n=nums.size();
        vector<long long> prefixSum(n,0);
        prefixSum[0]=0;
        for(int i=1;i<n;i++){
            prefixSum[i]=nums[i-1]+prefixSum[i-1];
        }   

        long long prod=1;
        for(int i=n-1;i>=0;i--){
            if(prod==prefixSum[i]) ans=i;
            if(prod>prefixSum[i]) break; // This is important to prevent overflow 
            prod*=nums[i];
        }
        return ans;
    }
};

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();

        vector<long long> sum(n, 0);
        vector<long long> product(n, 0);

        // prefix sum (elements strictly left)
        for (int i = 1; i < n; i++) {
            sum[i] = nums[i - 1] + sum[i - 1];
        }

        long long limit = (long long)1e14;  // Because the some doesn't exceed 1e14 (becasue there 1e5 elements & each ele is at max 1e9)

        // suffix product (elements strictly right)
        product[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (product[i + 1] > limit / nums[i + 1]) {  // THIS SHOULD BE REMEMBERED PROPERLY
                product[i] = limit;
            } else {
                product[i] = product[i + 1] * nums[i + 1];
            }
        }

        // find smallest balanced index
        for (int i = n - 1; i >= 0; i--) {
            if (sum[i] == product[i]) {
                return i;
            }
        }

        return -1;
    }
};
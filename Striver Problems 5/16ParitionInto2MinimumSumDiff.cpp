#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int half=n/2;
        vector<vector<int>> left(half+1),right(half+1);

        for(int i=0;i<(1<<half);i++){
            int sum=0,cnt=0;
            for(int j=0;j<half;j++){
                if( i & (1<<j) ){
                    sum+=nums[j];
                    cnt++;
                }
            }
            left[cnt].push_back(sum);
        }

        for(int i=0;i<(1<<half);i++){
            int sum=0,cnt=0;
            for(int j=0;j<half;j++){
                if( i & (1<<j) ){
                    sum+=nums[half+j];
                    cnt++;
                }
            }
            right[cnt].push_back(sum);
        }

        for(int i=0;i<half+1;i++){
            sort(right[i].begin(),right[i].end());
        }

        int mini=INT_MAX;
        int total=accumulate(nums.begin(),nums.end(),0);
        int target=total/2;

        for(int i=0;i<left.size();i++){
            int rightIndex=half-i;
            auto &vec=right[rightIndex];
            for(int j=0;j<left[i].size();j++){

                int need=target-left[i][j];              
                auto it = lower_bound(vec.begin(),vec.end(),need);

                if(it!=vec.end()) {
                    int sum=(*it)+left[i][j];
                    mini=min(mini,abs(total-2*sum)); // I had done target-sum that doesn't work 
                    // we should do total - 2*sum ; // Because sum is the value of "sum" of one part of array
                    // So another part will be "total-sum" 
                    // Now diff b/w "total-sum" and "sum" will be "total-2*sum"
                }
                if(it!=vec.begin()) {
                    int sum=(*(it-1))+left[i][j];
                    mini=min(mini,abs(total-2*sum));
                }
            }
        }
        return mini;
        
    }
};
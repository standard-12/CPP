#include<bits/stdc++.h>
using namespace std;

// This is LC 1755 (Closest SubSequence Sum) a prerequisite to solve the next problem (q.no 16 LC 2350)


// This uses a algorithm called Meet in the Middle 
// The constrain is 0<=N<=40 
// To get all subsets for this it will take 2^40 ~ 10^!2 operatoins which will give TLE
// And also DP FAILS HERE BECAUSE OF THE SUM RANGE (Not Because of n ) ( Sum can go up to 10^7 hence DP state will be 40*10^8 TLE/MLE etc)
// So we use meet in the middle where we split the n into two halves and apply Binary Search to the right side array 
// Hence Time Complexity will be 2^20+2^20 ( to generate subsets ) and 2^(N/2) * log (2^(N/2)) ( binary search for optimal sets ) 
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size(); 
        vector<int> left;
        generateAll(nums,0,(n+1)/2,0,left); // Left half
        vector<int> right;
        generateAll(nums,(n+1)/2,n,0,right); // Right Half

        sort(right.begin(),right.end());
        int i=0;
        int mini=INT_MAX;
        while(i<left.size()){
            int search=goal-left[i];
            auto it=lower_bound(right.begin(),right.end(),search); // Closes to goal can be found by using either lower_bound or floor
            if(it!=right.end()){ // lower_bound/ceil
                mini=min(mini,abs(goal-(left[i]+*it))); 
            }
            if(it!=right.begin()){ // floor
                mini=min(mini,abs(goal-(left[i]+*(it-1))));
            }
            i++;
        }
        return mini;
    }

    void generateAll(vector<int>& nums,int start,int end,int sum,vector<int>& ans){
        if(start==end){
            ans.push_back(sum);
            return;
        }
        generateAll(nums,start+1,end,sum+nums[start],ans);
        generateAll(nums,start+1,end,sum,ans);
    }
};


#include<bits/stdc++.h>
using namespace std;

// This was my solution i wasn't confident this would work but it worked and got accepted

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        queue<int> window;
        vector<int> ans(n-k+1,0);
        for(int i=0;i<k;i++){
            window.push(i);
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i=k;i<n;i++){

            int ind=window.front();
            window.pop();
        
            ans[i-k]=nums[dq.front()];
            if(ind==dq.front()){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
            window.push(i);
        }
        ans[n-k]=nums[dq.front()];
        return ans;
    }
};

// This is the optimal solution by striver same idea but compact
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n-k+1,0);
        deque<int> dq;
        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) ans[i-k+1]=nums[dq.front()];
        }
        return ans;
    }
};
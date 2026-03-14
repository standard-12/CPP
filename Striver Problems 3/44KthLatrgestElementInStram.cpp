#include<bits/stdc++.h>
using namespace std;

class KthLargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        int i=0;
        while(i<(int)nums.size()){
            if(pq.size()<K)
                pq.push(nums[i]);
            else if(pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }
    }
    
    int add(int val) {
        if(pq.size()<K || pq.top()<val){
            if(pq.size()==K) pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
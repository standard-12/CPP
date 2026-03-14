#include<bits/stdc++.h>
using namespace std;

// This was my solution  but there is a better solution
// I was using monotonic stack to update the values which can be updated by first method 
// And for other values i was using 2 pointers method
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,INT_MIN); // Because -1 initialization not working when the next greater elelment is -1
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(!st.empty() && st.top()>nums[i]){
                ans[i]=st.top();
            }
            st.push(nums[i]);
        }
        int i=0;
        int j=n-1;
        while(i<j){
            if(ans[j]!=INT_MIN) {
                j--;
            }
            else {
                while(i<j && nums[i]<=nums[j]){
                    i++;
                }
                if(i!=j) ans[j]=nums[i];
                j--;
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]==INT_MIN) ans[i]=-1;
        }
        return ans;
    }
};
// This is the optimal solution 
// Using the same method that is used for nge-1 problem but here array is double i.e allows to see circularly
// If given array is [1,2,5,3,4] we hypothetically do it as [1,2,5,3,4,1,2,5,3,4]
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--) { // Hypothetical Array of 2*n size
            while(!st.empty() && st.top()<=nums[i%n]){ // Hence modulo of n
                st.pop();
            }
            if(i<n){
                ans[i]=st.empty()? -1:st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};
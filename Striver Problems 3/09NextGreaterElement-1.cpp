#include<bits/stdc++.h>
using namespace std;

// The optimal solution using monotonic stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> ans(n1,-1);
        unordered_map<int,int> mp;
        for(int i=0;i<n1;i++){
            mp[nums1[i]]=i;
        }
        stack<int> st;
        for(int i=n2-1;i>=0;i--){ // Start from end
            while( !st.empty() && st.top() < nums2[i] ){ // Remove all small elements than the current element
                st.pop();
            }
            if(mp.count(nums2[i])){ // If it's there in the nums1
                if(!st.empty() && st.top()>nums2[i]) ans[mp[nums2[i]]]=st.top();
            }
            st.push(nums2[i]); // Add the current into stack
        }
        return ans;
    }
};
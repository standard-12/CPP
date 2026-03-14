#include<bits/stdc++.h>
using namespace std;

// I came up with this on my own but i confused and put < and > instead of <= and >=
// But this turned out to be not the  optimal solution
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prevSE(n,0);
        vector<int> nextSE(n,0);
        setPrev(heights,prevSE);
        setNext(heights,nextSE);
        int maxi=0;
        for(int i=0;i<n;i++){
            int width=nextSE[i]-prevSE[i]-1;
            maxi=max(heights[i]*width,maxi);
        }
        return maxi;
    }

    void setPrev(vector<int>& nums,vector<int>& ans){
        int n=nums.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i]=st.empty()? -1:st.top();
            st.push(i);
        }
    }

    void setNext(vector<int>& nums,vector<int>& ans){
        int n=nums.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i]=st.empty()? n:st.top();
            st.push(i);
        }
    }
};

// Same concept but in O(2n) Time and O(n) space instead of O(5n)
// We calculate pse on the fly (i.e while calculating the answer itself) 
// And nse is found when we pop out the element from the stack i.e nse will be responsible for popping out of an element
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int maxi=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int val=heights[st.top()];
                int nse=i; // The elelent which is responsible for popping is the nse
                st.pop();       // Pop so we can see if pse exists or not
                int pse=st.empty()? -1:st.top(); // If there is a pse for the popped elelment 
                int width=nse-pse-1;
                maxi=max(maxi,val*width);
            }
            st.push(i); // Push index not the element
        }
        while(!st.empty()){ // Stack has elements which doesn't have nse
            int val=heights[st.top()];
            int nse=n;
            st.pop();
            int pse=st.empty()? -1:st.top();
            int width=nse-pse-1;
            maxi=max(maxi,val*width);
        }
        return maxi;
    }
};
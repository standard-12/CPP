#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n=arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(!st.empty() ) ans[i]=st.top();
            else ans[i]=-1;
            
            st.push(arr[i]);
        }
        return ans;
    }
};
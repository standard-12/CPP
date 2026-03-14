#include<bits/stdc++.h>
using namespace std;

// Time Complexity -O(5n) Space Complexity - O(5n) (including different stcks used in different code);
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nextSE(n); // We are storing index(not the element) of Next Smaller Element
        vector<int> prevSEE(n); // Storing index of previous Smaller or Equal(to overcome the edge case of [1,1])
        set_prevSEE(arr,prevSEE);
        set_nextSE(arr,nextSE);
        const int MOD = 1'000'000'007;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prevSEE[i];         // >=1
            long long right = nextSE[i] - i;         // >=1
            long long contrib = (left * right) % MOD;
            contrib = (contrib * (arr[i] % MOD)) % MOD;
            ans = (ans + contrib) % MOD;
        }
        return int(ans);
    }

    void set_prevSEE(vector<int>& values,vector<int>& ans){ // Store greater or equal
        int n=ans.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && values[i]<values[st.top()]){ // hence pop only greater
                st.pop();
            }
            ans[i]=st.empty()? -1:st.top();
            st.push(i);
        }
    }

    void set_nextSE(vector<int>& values,vector<int>& ans){
        int n=ans.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && values[i]<=values[st.top()]){ // hence pop greater and equal
                st.pop();
            }
            ans[i]=st.empty()? n:st.top();
            st.push(i);
        }
    }
};
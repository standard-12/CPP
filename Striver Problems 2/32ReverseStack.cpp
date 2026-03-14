#include<bits/stdc++.h>
using namespace std;

// Time Complexity O(n^2)
// Space O(1) if we ignore stack space or else O(n)
class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int top=st.top();
        st.pop();
        reverseStack(st);
        insertatBottom(st,top);
    }
    void insertatBottom(stack<int>& st,int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int top=st.top();
        st.pop();
        insertatBottom(st,x);
        st.push(top);
    }
};
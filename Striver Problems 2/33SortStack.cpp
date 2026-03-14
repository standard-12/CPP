#include<bits/stdc++.h>
using namespace std;

// Time Complexity O(n^2)
// Space O(1) if we ignore stack space or else O(n)
class Solution {
  public:
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int top=st.top();
        st.pop();
        sortStack(st);
        sortedInsert(st,top);
    }
    
    void sortedInsert(stack<int>& st,int x){
        if(st.empty() || st.top()<=x){
            st.push(x);
            return ;
        }
        int top =st.top();
        st.pop();
        sortedInsert(st,x);
        st.push(top);
    }
};
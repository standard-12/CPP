#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToPost(string pre_exp) {
        int n=pre_exp.size();
        int i=n-1;
        string s=pre_exp;
        stack<string> st;
        while(i>=0){
            if(isalnum(s[i])){
                string str(1,s[i]);
                st.push(str);
            }
            else {
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                st.push(s1+s2+s[i]); // See the pattern here also
            }
            i--;
        }
        return st.top();
    }
};
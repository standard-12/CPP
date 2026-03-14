#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string postToPre(string post_exp) {
        int n=post_exp.size();
        int i=0;
        string s=post_exp;
        stack<string> st;
        while(i<n){
            if(isalnum(s[i])){
                string str(1,s[i]);
                st.push(str);
            }
            else {
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                st.push(s[i]+s2+s1); // Note the pattern of pushing
            }
            i--;
        }
        return st.top();
    }
};
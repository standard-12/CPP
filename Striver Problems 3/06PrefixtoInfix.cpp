#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToInfix(string pre_exp) {
        int i=pre_exp.size()-1;
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
                st.push('('+s1+s[i]+s2+')'); // Here s1+s2 in previous one s2+s1
            }
            i--;
        }
        return st.top();
    }
};
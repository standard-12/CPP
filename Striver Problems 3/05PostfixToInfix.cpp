#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        int i=0;
        int n=exp.size();
        string s=exp;
        stack<string> st;
        while(i<n){
            if(isalnum(s[i])){
                string str(1,s[i]);
                st.push(str);
            }
            else if(isoperator(s[i])){
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                st.push('('+s2+s[i]+s1+')');
            }
            i++;
        }
        return st.top();
    }
    
    bool isoperator(char ch){
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/') return true;
        return false;
    }
};

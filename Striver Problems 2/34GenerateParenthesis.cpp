#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
            vector<string> ans;
            string s="(";
            helper(s,2*n,ans);
            return ans;   
    }

    void helper(string s,int n,vector<string>& ans){
        if(!optimizer(s)) return;
        if(n==(int)s.size()){
            if(isValid(s)) ans.push_back(s);
            return;
        }
        helper(s+")",n,ans);
        helper(s+"(",n,ans);
    }

    bool isValid(string& s){
        int n=s.size();
        stack<char> st;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                st.push('(');
            }
            else {
                if(st.empty()) return false;
                st.pop();
            }
            i++;
        }
        if(st.empty()) return true;
        return false;
    }

    bool optimizer(string s){
        int n=s.size();
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt1++;
            else cnt2++;
            if(cnt2>cnt1) return false; 
        }
        return true;
    }
};

// this only generates valid parenthesis still not the best since we are trying to generate everything and coming back if optimizer fails
class Solution {
public:
    vector<string> generateParenthesis(int n) {
            vector<string> ans;
            string s="(";
            helper(s,2*n,ans);
            return ans;   
    }

    void helper(string s,int n,vector<string>& ans){
        if(!optimizer(s,n)) return;
        if(n==(int)s.size()){
            // if(isValid(s)) ans.push_back(s);
            ans.push_back(s);
            return;
        }
        helper(s+")",n,ans);
        helper(s+"(",n,ans);
    }

    bool isValid(string& s){
        int n=s.size();
        stack<char> st;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                st.push('(');
            }
            else {
                if(st.empty()) return false;
                st.pop();
            }
            i++;
        }
        if(st.empty()) return true;
        return false;
    }
    bool optimizer(string s,int len){
        int n=s.size();
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt1++;
            else cnt2++;
            if(cnt2>cnt1 || cnt1>len/2) return false; 
        }
        return true;
    }
};

// This generates only the valid parenthesises with also using backtracking

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        helper(s,n,n,ans);
        return ans;
    }

    void helper(string& s,int open,int close,vector<string>& ans){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open>0) {
            s.push_back('(');
            helper(s,open-1,close,ans);
            s.pop_back();
        }
        if(close>open) {
            s.push_back(')');
            helper(s,open,close-1,ans);
            s.pop_back();
        }
    }
};
#include<bits/stdc++.h>
using namespace std;
// This is the optimal solution
class Solution {
public:
    vector<string> ans;
    string s;
    int target;
    vector<string> addOperators(string s, int target) {
        this->s = s;
        this->target = target;
        backtrack( 0, "", 0, 0);
        return ans;
    }
    void backtrack(int i, const string& path, long resSoFar, long prevNum) {
        if (i == s.length()) {
            if (resSoFar == target) ans.push_back(path);
            return;
        }
        string numStr;
        long num = 0;
        for (int j = i; j < s.length(); j++) {
            if (j > i && s[i] == '0') break; // Skip leading zero number
            numStr += s[j];
            num = num * 10 + s[j] - '0';
            if (i == 0) {
                backtrack(j + 1, path + numStr, num, num); // First num, pick it without adding any operator!
            } else {
                backtrack(j + 1, path + "+" + numStr, resSoFar + num, num);
                backtrack(j + 1, path + "-" + numStr, resSoFar - num, -num);
                backtrack(j + 1, path + "*" + numStr, resSoFar - prevNum + prevNum * num, prevNum * num); // Can imagine with example: 1-2*3
            }
        }
    }
};


// THis is what i trie but it didn't work i was converting it to postfix then evaluating etc but got to know many string functions
// such as s.insert(pos,string) , s.erase(pos,len) , stoi(string)
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<char> ops={'+','-','*'};
        vector<string> ans;
        recur(num,ans,1,target);
        return ans;
    }

    void recur(string& num,vector<string>& ans,int index,int target){
        vector<string> post=eval(num);
        if(postfixEval(post)==target) ans.push_back(num);
        if(index>=num.size()) return; 
        num.insert(index,"+");
        recur(num,ans,index+2,target);
        num.erase(index,1);
        num.insert(index,"-");
        recur(num,ans,index+2,target);
        num.erase(index,1);
        num.insert(index,"*");
        recur(num,ans,index+2,target);
        num.erase(index,1);
    }

    vector<string> eval(string& s){
        int i=0;
        int n=s.size();
        stack<char> st;
        vector<string> postfix;
        while(i<n){
            if(s[i]== '+' || s[i]=='-' || s[i]=='*'){
                if(s[i]=='*'){
                    while(!st.empty() && st.top()=='*'){
                        char ch=st.top();
                        st.pop();
                        string s3(1,ch);
                        postfix.push_back(s3);
                    }
                    st.push(s[i]);
                }
                else if(s[i]=='+' || s[i]=='-'){
                    while(!st.empty() && st.top()=='*'){
                        char ch=st.top();
                        st.pop();
                        string s1(1,ch);
                        postfix.push_back(s1);
                    }
                    st.push(s[i]);
                }
                i++;
            }
            else {
                string s2;
                while(i<n && s[i]!='+' && s[i]!='-' && s[i]!='*'){
                    s2.push_back(s[i]);
                    i++;
                }
                postfix.push_back(s2);
            }
        }
        while(!st.empty()){
            char ch=st.top();
            st.pop();
            string p(1,ch);
            postfix.push_back(p);
        }
        return postfix;
    }

    int postfixEval(vector<string>& postfix){
        stack<int> st;
        int i=0;
        while(i<postfix.size()){
            if(postfix[i]=="+" || postfix[i]=="-" || postfix[i]=="*"){
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                int ans=0;
                if(postfix[i]=="+") ans=op1+op2;
                else if(postfix[i]=="-") ans=op2-op1;
                else if(postfix[i]=="*") ans=op2*op1;
                st.push(ans);
                i++;
            }
            else {
                if(postfix[i].size()>0){
                long long t1=stoi(postfix[i]);
                st.push(t1);
                i++;
                }
            }
        }
        return st.top();
    }
};


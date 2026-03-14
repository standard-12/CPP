#include<bits/stdc++.h>
using namespace std;

// I solved this on my own after many tries and dry runs so proud of it 
// there are many edge cases to note on this problem
// Eg 1. If n==k return 0;
//    2. If my ans was "0" and while removing leading zeroes if i remove that zero also then it'll be ""
//    3. Puhs only if stack is less than the ans length
// All these edge cases are handled neatly in striver solution i have handlet it but its not that neat
class Solution {
public:
    string removeKdigits(string num, int k) {
        int digits=num.size();
        vector<int> vec;
        for(int i=0;i<digits;i++){
            vec.push_back(num[i]-'0');
        }
        int n=vec.size();
        stack<int> st;
        int ansLen=digits-k;
        int i=0;
        if(digits==k) return "0";
        while(i<n){
                    while(!st.empty() && n-i>ansLen-st.size() && vec[i]<st.top()){
                        st.pop();
                    }
                    if(st.size()<ansLen) st.push(vec[i]);
                    i++;
        }
        string s;
        while(!st.empty()){
            char ch='0'+st.top();
            s.push_back(ch);
            st.pop();
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!='0') break;
            else s.pop_back();
        }
        if(s=="") s="0";
        reverse(s.begin(),s.end());
        return s;
    }
};

// Time Complexity O(3n)+O(k)
// Space Complexity O(2n)

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0) {
            st.pop();
            k--;
        }
        string s;
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        while(s.size()>0 && s.back()=='0'){
            s.pop_back();
        }
        reverse(s.begin(),s.end());
        if(s.empty()) return "0";
        else return s;
    }
};
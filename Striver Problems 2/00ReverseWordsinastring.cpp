#include<bits/stdc++.h>
using namespace std;
// The first solution with stack i could'nt find like i was trying with stack<char> but it was not working for spaces
// stack<string> case is more readable
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string result;
        string word;
        stack<string> st;
        int i=0;
        while(i<n){
            if(s[i]!=' '){
                word.push_back(s[i]);
                i++;
            }
            else {
                if(!word.empty()){
                    st.push(word);
                    word.clear();
                }
                while(i<n&& s[i]==' ') i++;
            }
        }
        if(!word.empty()) st.push(word);

        while(!st.empty()){
            result.append(st.top());
            st.pop();
            if(!st.empty()) result.push_back(' ');
        }
        return result;
    }
};
// I did O(1) solution but it was a not pretty ( that is what chatgpt said )
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        while(s[i]==' ') i++;
        while(s[j]==' ') j--;
        int k=0;
        int len=j-i+1;
        while(i<=j){
            if(s[i]!=' ') {
                k++;
                i++;
            }
            else {
                k++;
                while(i<=j && s[i]==' ') i++;
            }
        }
        i=i-len;
        string ans(k,' ');
        int count=0;
        for(;i<=j;i++){
            if(s[i]!=' '){
                count++;
                ans[--k]=s[i];
            }
            else {
                reverse(ans.begin()+k,ans.begin()+k+count);
                count=0;
                ans[--k]=' ';
                while(i<=j && s[i]==' ') i++;
                i--; // because i dumb ass used for loop i knew i can use while but just to see so to maintain increment of for loop i should do one decrement
            }
        }
        reverse(ans.begin()+k,ans.begin()+k+count);
        return ans;
    }
};
// This is the optimal solution using O(1) space
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        // Step 1: remove extra spaces (leading, trailing, and multiple between words)
        int i = 0, j = 0;
        while (j < n) {
            // skip spaces
            while (j < n && s[j] == ' ') j++;
            // copy word
            while (j < n && s[j] != ' ') s[i++] = s[j++];
            // skip spaces between words, keep only one
            while (j < n && s[j] == ' ') j++;
            if (j < n) s[i++] = ' ';
        }
        s.resize(i);  // shrink to new size

        // Step 2: reverse the whole string
        reverse(s.begin(), s.end());

        // Step 3: reverse each word
        int start = 0;
        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};

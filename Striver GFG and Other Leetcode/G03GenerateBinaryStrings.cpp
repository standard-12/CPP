#include<bits/stdc++.h>
using namespace std;

// To generate all binary strings of length n without consecutive one's

// I am happy i came up with this solution on my own even though its inefficient it works
// I am trying out all possibilities and adding if its valid
class Solution {
  public:
    vector<string> generateBinaryStrings(int num) {
        vector<string> ans;
        string s;
        append0(s,num,ans);
        append1(s,num,ans);
        return ans;
    }
    void append0(string s,int n,vector<string>& v){
        s.append("0");
        if(s.size()==n) {
            addToAnswer(v,s);
            return;
        }

        append0(s,n,v);
        append1(s,n,v);
        return;
    }
    
    void append1(string s,int n,vector<string>& v){
        s.append("1");
        if(s.size()==n){
            addToAnswer(v,s);
            return;
        }

        append0(s,n,v);
        append1(s,n,v);
        return;
    }

    
    void addToAnswer(vector<string>& v,string& s){
        int n=s.size();
        bool b=true;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1] && s[i]=='1') {
                b=false;
                break;
            }
        }
        if(b) v.push_back(s);
        return;
    }
};


// This is the optimal recursion solution which only generates valid strings without consecutive one's
class Solution {
  public:
    void helper(int num, vector<string>& ans, int prevState, string temp){
        if(num == 0){
            ans.push_back(temp);
            return;
        }
        if(prevState == 1){
            helper(num - 1, ans, 0, temp+"0");
        }
        else{
            helper(num - 1, ans, 1, temp+"1");
            helper(num - 1, ans, 0, temp+"0");
        }
    }
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string> ans;
        helper(num, ans, 0, "");
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// This is doing same but with backtracking i.e string is passed with reference so less space complexity and also less time since direct 
// concation(with str + '0' ) requires O(n) time where push_back takes O(1)

class Solution {
public:
    void backtrack(int n, vector<string>& ans, string& temp, int prev) {
        if (n == 0) {
            ans.push_back(temp);
            return;
        }

        // Always allowed to place '0'
        temp.push_back('0');
        backtrack(n - 1, ans, temp, 0);
        temp.pop_back();

        // Only place '1' if prev was not 1
        if (prev == 0) {
            temp.push_back('1');
            backtrack(n - 1, ans, temp, 1);
            temp.pop_back();
        }
    }

    vector<string> generateBinaryStrings(int num) {
        vector<string> ans;
        string temp;
        backtrack(num, ans, temp, 0);
        sort(ans.begin(), ans.end()); // optional, if lexicographic order is required
        return ans;
    }
};

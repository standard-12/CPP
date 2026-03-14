#include<bits/stdc++.h>
using namespace std;

// Different type of problem but i was able to solve yehhhh  

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char>> mp;
        initialize(mp);
        vector<string> ans;
        string s;
        if(digits.size()==0) return ans;
        recur(0,s,digits,ans,mp);
        return ans;
    }

    void recur(int index,string& s,string& digits,vector<string>& ans,unordered_map<char,vector<char>>& mp){
        if((int)s.size()==(int)digits.size()){
            ans.push_back(s);
            return;
        }
        vector<char> temp=mp[digits[index]];
        for(int i=0;i<temp.size();i++){
            s.push_back(temp[i]);
            recur(index+1,s,digits,ans,mp); // It is index+1 not i+1 because for every letter in current array we want next letter in the next array
            s.pop_back();
        }
    }
    void initialize(unordered_map<char,vector<char>>& mp){
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};       
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
    }
};

// Just for knowledge it has iterative solution but not simple
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> ans = {""};

        for (char digit : digits) {
            vector<string> temp;
            for (string s : ans) {
                for (char c : mp[digit]) {
                    temp.push_back(s + c);
                }
            }
            ans.swap(temp);  // Swap means memory spaces are swapped 
            // temp becomes ans and ans becomes temp;
        }

        return ans;
    }
};

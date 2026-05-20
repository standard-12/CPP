#include<bits/stdc++.h>
using namespace std;

// Q.no LC49
// This was also a nice quesiton to me i solved it on my own but that could have been done with lesser code 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<string> copy=strs;
        for(int i=0;i<n;i++){
            sort(copy[i].begin(),copy[i].end());
        }

        unordered_map<string,vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[copy[i]].push_back(i);
        }

        vector<vector<string>> ans;
        for(auto& it:mp){
            string s=it.first;
            vector<int> v=it.second;
            vector<string> temp;
            for(int i=0;i<v.size();i++){
                int index=v[i];
                temp.push_back(strs[index]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// The cleaner version 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(string s : strs) {

            string key = s;
            sort(key.begin(), key.end());

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto& it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
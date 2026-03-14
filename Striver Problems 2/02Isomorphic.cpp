#include<bits/stdc++.h>
using namespace std;

// this was my solution 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size(); 
        unordered_map<char,char> mps;
        unordered_map<char,char> mpt;
        for(int i=0;i<n;i++){
            if(mps.count(s[i])){
                if(mps[s[i]]!=t[i]) return false;
            }
            else 
                mps[s[i]]=t[i];
            if(mpt.count(t[i])){
                if(mpt[t[i]]!=s[i]) return false;
            }
            else 
                mpt[t[i]]=s[i];
        }
        return true;
    }
};

// another solution which is more elegant it stores the last index that character appeared in an array of size 256
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        
        int mps[256]={0};
        int mpt[256]={0};

        for(int i=0;i<n;i++){
        unsigned char sc=s[i];
        unsigned char tc=t[i];

        if(mps[sc]!=mpt[tc]) return false;
        mps[sc]=mpt[tc]=i+1;
        }
        return true;
    }  
};
#include<bits/stdc++.h>
using namespace std;

// This was my solution but this can be optimized to use only one array and do ++ one string and -- for another string 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int mps[256]={0};
        int mpt[256]={0};
        for(int i=0;i<s.size();i++){
            unsigned char sc=s[i];
            unsigned char st=t[i];
            mps[sc]++;
            mpt[st]++;
        }
        for(int i=0;i<256;i++){
            if(mps[i]!=mpt[i]) return false;
        }
        return true;
    }
};
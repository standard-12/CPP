#include<bits/stdc++.h>
using namespace std;

// This is wrong since the question was not properly explained in leetcode (see discussion)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        int word_n=wordDict.size();
        vector<bool> marker(word_n,false);

        for(int i=0;i<n;i++){
            int wordsize;
            bool found=false;

            for(int j=0;j<word_n;j++){
                if(wordDict[j][0]==s[i]){
                    wordsize=wordDict[j].size();
                    int s_ind=i;
                    bool equal=true;
                    for(int k=0;k<wordsize;k++){
                        if(wordDict[j][k]!=s[s_ind]){
                            equal=false;
                            break;
                        }
                        s_ind++;
                    }
                    if(equal) {
                        marker[j]=true;
                        found=true;
                        break;
                    }
                }
            }

            if(found){
                i=i+wordsize-1; // -1 because i gets incremented again
            }
            else {
                return false;
            }
        }
        
        for(int i=0;i<marker.size();i++){
            if(marker[i]==false) return false;
        }
        return true;
    }
};

// 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(0, s, dict);
    }

private:
    bool dfs(int idx, const string &s, const unordered_set<string> &dict) {
        int n = s.size();
        if (idx == n) return true;            // reached end => success

        // Try every word in the dictionary as a prefix at position idx
        for (const auto &w : dict) {
            int m = w.size();
            if (idx + m <= n && s.compare(idx, m, w) == 0) { // match without creating substr
                if (dfs(idx + m, s, dict)) return true;      // if remainder works, success
            }
        }
        return false; // no word leads to a complete segmentation
    }
};

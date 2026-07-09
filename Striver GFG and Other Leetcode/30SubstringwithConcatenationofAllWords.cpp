#include<bits/stdc++.h>
using namespace std;

// I had found the right idea ,but i had missed a small detail (that i should start from 0 to wordLen(i was only starting from 0)
// later after seeing GPT and correcting ,it got accepted but it was not completely optimized

// This was my solution 

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int wordLen=words[0].size();
        int n2=words.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n2;i++){
            mp[words[i]]++;
        }

        for(int i=0;i<wordLen;i++) solver(s,words,ans,i,mp);
        return ans;
    }
    void solver(string s, vector<string>& words,vector<int>& ans,int startInd,unordered_map<string,int>& mp) {
        int n=s.size();
        int n2=words.size();
        int wordLen=words[0].size();
        int StringLen=wordLen*n2;

        int j=startInd,i=startInd;
        unordered_map<string,int> runTime;
        while(i<n){
            while(i<n && i-j<StringLen){
                int curr=0;
                string temp="";
                while(i<n && curr<wordLen){
                    temp+=s[i];
                    i++;
                    curr++;
                }
                if(mp.count(temp)){
                    runTime[temp]++;
                }
            }
            bool b=check(mp,runTime);
            if(b) ans.push_back(j);
            int t2=0;
            string rem="";
            while(j<i && t2<wordLen){
                rem+=s[j];
                j++;
                t2++;
            }
            if(mp.count(rem)){
                runTime[rem]--;
            }
        }
    }
    bool check(unordered_map<string,int>& original,unordered_map<string,int>& compare){
        for(auto& it:original){
            if(compare.count(it.first) && compare[it.first]==it.second) continue;
            else return false;
        }
        return true;
    }
};

// This is completely Optimal

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if(words.empty() || s.empty()) return ans;

        int wordLen = words[0].size();
        int totalWords = words.size();

        unordered_map<string,int> target;

        for(auto &w : words)
            target[w]++;

        for(int offset = 0; offset < wordLen; offset++) {

            unordered_map<string,int> window;

            int left = offset;
            int right = offset;

            int count = 0;

            while(right + wordLen <= s.size()) {

                string word = s.substr(right, wordLen);
                right += wordLen;

                // Invalid word
                if(!target.count(word)) {
                    window.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                window[word]++;
                count++;

                // Too many copies of this word
                while(window[word] > target[word]) {

                    string remove = s.substr(left, wordLen);

                    window[remove]--;
                    left += wordLen;
                    count--;
                }

                // Found a valid window
                if(count == totalWords) {

                    ans.push_back(left);

                    string remove = s.substr(left, wordLen);
                    window[remove]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};
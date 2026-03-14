#include<bits/stdc++.h>
using namespace std;

// LeetCode Weekly Contest 472 3rd Question (LC 3720)

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        string ans="";
        string temp;
        vector<int> vis(26,0);
        for(int i=0;i<s.size();i++){ // Keep track of the charcter frequencies because only these are to be user later
            vis[s[i]-'a']++;
        }
        bool b=recur(target,temp,ans,vis,false); // Send false since the current temp (empty string) is not bigger than target 
        return ans;
    }

    bool recur(string& target,string& temp,string& ans,vector<int>& vis,bool big){
        // if(temp!= "" && temp.compare(target)<0) return;
        if(temp.size()==target.size()){
            if(big) {
                ans=temp;
                return true;
            }
            return false;
        }
        int index=temp.size();
        char compare=target[index];
        for(int i=0;i<26;i++){
            if(vis[i]==0) continue;
            if(!big && 'a'+i < compare) continue;  // Because of this condition it only adds a character if it is greater than corresponding 
            // target character i.e when big is true (i.e when the temp is bigger than target(any one char in temp is strictly greater than
            // target) lexiographically ) it doesn't continue i.e it adds characters in sorted order
  
            bool newBig = big || ('a'+i > compare);
            temp.push_back(char('a'+i));
            vis[i]--;
            if(recur(target,temp,ans,vis,newBig)) return true;
            temp.pop_back();
            vis[i]++;
        }
        return false;
    }

};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPermutationGreater(string s, string target) {
        int n = s.size();
        if ((int)target.size() != n) return "";

        // count chars in s
        vector<int> cnt(26, 0);
        for (char ch : s) cnt[ch - 'a']++;

        // Build prefix as long as we can match target chars
        string prefix;
        int i = 0;
        for (; i < n; ++i) {
            int t = target[i] - 'a';
            if (cnt[t] > 0) {
                prefix.push_back(target[i]);
                cnt[t]--;
            } else {
                break; // cannot match target[i]
            }
        }

        // If we've consumed entire target (prefix length == n), we still need strictly greater,
        // so start backtracking from last index n-1.
        int startJ = (i == n ? n - 1 : i);

        // Backtrack from startJ down to 0.
        // Note: cnt currently reflects characters left after consuming prefix (target[0..i-1]).
        for (int j = startJ; j >= 0; --j) {
            // If j < i (i.e., j < matched length), we restore prefix[j] to cnt
            // because we are considering changing an earlier position.
            if (j < i) {
                // restore prefix[j] char into counts before trying to change position j
                cnt[prefix[j] - 'a']++;
            }

            // determine the character currently at position j in our tentative string:
            // - if j < i, it was prefix[j] (which equals target[j])
            // - if j == i (the first unmatched position), it's target[j]
            int curChar = (j < i ? prefix[j] - 'a' : target[j] - 'a');

            // try to find smallest character strictly greater than curChar
            for (int c = curChar + 1; c < 26; ++c) {
                if (cnt[c] > 0) {
                    // build answer:
                    string ans;
                    // append prefix up to j (exclusive)
                    ans = prefix.substr(0, j);
                    // append the chosen greater character
                    ans.push_back(char('a' + c));
                    // decrement the chosen char count
                    cnt[c]--;

                    // append remaining characters in ascending order
                    for (int k = 0; k < 26; ++k) {
                        while (cnt[k]-- > 0) ans.push_back(char('a' + k));
                    }

                    return ans; // smallest lexicographic completion found
                }
            }
            // nothing works at position j -> continue to move left (next iteration will restore more)
        }

        // no valid greater permutation
        return "";
    }
};
